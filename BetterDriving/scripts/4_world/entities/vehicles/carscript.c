modded class CarScript
{
	protected const float AUTO_SHIFT_UPSHIFT_RPM_RATIO = 0.9;
	protected const float AUTO_SHIFT_DOWNSHIFT_RPM_RATIO = 0.4;
	protected const float AUTO_SHIFT_THROTTLE_THRESHOLD = 0.2;
	protected const float AUTO_SHIFT_NEUTRAL_THROTTLE_THRESHOLD = 0.1;
	protected const float AUTO_SHIFT_COOLDOWN_TIME = 0.35;
	protected const float AUTO_SHIFT_NEUTRAL_MAX_SPEED = 3.0;
	protected const float AUTO_SHIFT_NEUTRAL_STOP_SPEED = 1.5;
	protected const float AUTO_SHIFT_REVERSE_BRAKE = 1.0;
	protected const float AUTO_SHIFT_NEUTRAL_BRAKE_DELAY = 0.75;
	protected const float AUTO_SHIFT_NEUTRAL_BRAKE_STRENGTH = 0.4;
	protected const float AUTO_SHIFT_REVERSE_BRAKE_THRESHOLD = 0.2;
	protected const float AUTO_SHIFT_FORWARD_BRAKE = 0.6;
	protected const float AUTO_SHIFT_BRAKE_RAMP_TIME = 0.5;
	protected const float AUTO_SHIFT_OVERREV_LIMIT_RATIO = 0.98;
	protected const float AUTO_SHIFT_OVERREV_THROTTLE_CAP = 0.2;
	protected const float AUTO_SHIFT_REVERSE_OVERREV_LIMIT_RATIO = 0.7;

	protected float m_AutoShiftCooldown;
	protected float m_AutoNeutralBrakeTimer;
	protected float m_AutoBrakeRamp;

	override void OnUpdate(float dt)
	{
		super.OnUpdate(dt);

		if (GetNetworkMoveStrategy() == NetworkMoveStrategy.PHYSICS)
		{
			if (!IsOwner())
				return;
		}
		else
		{
			if (!GetGame().IsServer())
				return;
		}

		if (GearboxGetType() != CarGearboxType.MANUAL)
			return;

		if (!EngineIsOn())
			return;

		Human driver = CrewDriver();
		if (!driver || !driver.IsControllingVehicle())
			return;

		if (m_AutoShiftCooldown > 0)
		{
			m_AutoShiftCooldown -= dt;
			return;
		}

		float throttle = GetThrottle();
		float speed = GetSpeedometerAbsolute();
		float rpm = EngineGetRPM();
		float rpmRedline = EngineGetRPMRedline();
		float upshiftRpm = rpmRedline * AUTO_SHIFT_UPSHIFT_RPM_RATIO;
		float downshiftRpm = rpmRedline * AUTO_SHIFT_DOWNSHIFT_RPM_RATIO;
		int currentGear = GetGear();
		int neutralGear = GetNeutralGear();
		int gearCount = GetGearCount();
		if (gearCount <= 0)
			gearCount = GetGearsCount(); // [Obsolete] fallback for mods that still rely on the older API
		int maxGear = gearCount - 1;
		TFloatArray gearboxRatios = new TFloatArray;
		GetGame().ConfigGetFloatArray("cfgVehicles " + GetType() + " SimulationModule Gearbox ratios", gearboxRatios);
		if (gearboxRatios.Count() > 0)
		{
			int maxGearFromRatios = CarGear.FIRST + gearboxRatios.Count() - 1;
			if (maxGear < maxGearFromRatios)
				maxGear = maxGearFromRatios;
		}
		if (maxGear < CarGear.FIRST)
			return;

		// Based on Scripts/3_game/vehicles/car.c : GearboxGetType(), ShiftTo(), EngineGetRPMRedline(), GetGearCount().
		if (currentGear == CarGear.REVERSE)
		{
			float brakeReverse = GetBrake();
			SetBrake(0);
			bool reverseOverrev = rpm >= rpmRedline * AUTO_SHIFT_REVERSE_OVERREV_LIMIT_RATIO;
			float reverseThrottle = brakeReverse;
			if (reverseOverrev)
				reverseThrottle = 0;
			if (throttle > AUTO_SHIFT_NEUTRAL_THROTTLE_THRESHOLD)
			{
				m_AutoBrakeRamp = Math.Clamp(m_AutoBrakeRamp + (dt / AUTO_SHIFT_BRAKE_RAMP_TIME), 0, 1);
				SetBrake(AUTO_SHIFT_FORWARD_BRAKE * m_AutoBrakeRamp);
				SetThrottle(0);
				if (speed <= AUTO_SHIFT_NEUTRAL_STOP_SPEED)
				{
					ShiftTo(neutralGear);
					m_AutoShiftCooldown = AUTO_SHIFT_COOLDOWN_TIME;
				}
				return;
			}
			m_AutoBrakeRamp = 0;

			if (reverseThrottle > AUTO_SHIFT_REVERSE_BRAKE_THRESHOLD)
			{
				SetThrottle(reverseThrottle);
			}
			else
			{
				SetThrottle(0);
			}

			if (brakeReverse <= AUTO_SHIFT_REVERSE_BRAKE_THRESHOLD && speed <= AUTO_SHIFT_NEUTRAL_STOP_SPEED)
			{
				ShiftTo(neutralGear);
				m_AutoShiftCooldown = AUTO_SHIFT_COOLDOWN_TIME;
			}
			return;
		}

		if (currentGear == neutralGear)
		{
			float brake = GetBrake();
			if (throttle > AUTO_SHIFT_NEUTRAL_THROTTLE_THRESHOLD)
			{
				m_AutoNeutralBrakeTimer = 0;
				m_AutoBrakeRamp = 0;
				if (speed <= AUTO_SHIFT_NEUTRAL_MAX_SPEED)
				{
					ShiftTo(CarGear.FIRST);
					m_AutoShiftCooldown = AUTO_SHIFT_COOLDOWN_TIME;
				}
				return;
			}

			if (brake > AUTO_SHIFT_REVERSE_BRAKE_THRESHOLD)
			{
				m_AutoNeutralBrakeTimer = 0;
				if (speed > AUTO_SHIFT_NEUTRAL_STOP_SPEED)
				{
					m_AutoBrakeRamp = Math.Clamp(m_AutoBrakeRamp + (dt / AUTO_SHIFT_BRAKE_RAMP_TIME), 0, 1);
					SetBrake(AUTO_SHIFT_REVERSE_BRAKE * m_AutoBrakeRamp);
				}
				else
				{
					m_AutoBrakeRamp = 0;
					SetBrake(0);
					ShiftTo(CarGear.REVERSE);
					m_AutoShiftCooldown = AUTO_SHIFT_COOLDOWN_TIME;
				}
				return;
			}
			m_AutoBrakeRamp = 0;

			m_AutoNeutralBrakeTimer += dt;
			if (m_AutoNeutralBrakeTimer >= AUTO_SHIFT_NEUTRAL_BRAKE_DELAY && speed > AUTO_SHIFT_NEUTRAL_STOP_SPEED)
			{
				SetBrake(AUTO_SHIFT_NEUTRAL_BRAKE_STRENGTH);
			}
			return;
		}

		if (currentGear < CarGear.FIRST)
			return;

		if (currentGear == maxGear && rpm >= rpmRedline * AUTO_SHIFT_OVERREV_LIMIT_RATIO)
		{
			SetThrottle(Math.Min(throttle, AUTO_SHIFT_OVERREV_THROTTLE_CAP));
			return;
		}

		m_AutoNeutralBrakeTimer = 0;

		if (speed <= AUTO_SHIFT_NEUTRAL_STOP_SPEED && throttle <= AUTO_SHIFT_NEUTRAL_THROTTLE_THRESHOLD)
		{
			ShiftTo(neutralGear);
			m_AutoShiftCooldown = AUTO_SHIFT_COOLDOWN_TIME;
			return;
		}

		if (currentGear < maxGear && throttle > AUTO_SHIFT_THROTTLE_THRESHOLD && rpm >= upshiftRpm)
		{
			ShiftTo(currentGear + 1);
			m_AutoShiftCooldown = AUTO_SHIFT_COOLDOWN_TIME;
			return;
		}

		if (currentGear > CarGear.FIRST && rpm <= downshiftRpm)
		{
			ShiftTo(currentGear - 1);
			m_AutoShiftCooldown = AUTO_SHIFT_COOLDOWN_TIME;
		}
	}
}