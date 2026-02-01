modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();
		if (GetGame().IsServer())
			Print("[BetterDriving] Initialised BetterDriving mod!");
	}
}