modded class CarScript
{
    protected static const float PROTRACTION_MIN_SPEED = 0.1; // Minimum speed threshold for traction control
    protected static const float PROTRACTION_YAW_SCALE = 0.35; // Scale factor for yaw damping
    protected static const float PROTRACTION_STEERING_THRESHOLD = 0.2; // Steering threshold for applying traction control

    protected void ApplyProTraction(float timeSlice)
    {
        // Execute on server + vehicle owner
        if (!IsServerOrOwner())
        {
            return;
        }

        int wheelCount = WheelCount(); // Check wheel traction
        if (wheelCount <= 0)
        {
            return; // Exit if no traction
        }

        // Track wheel contact
        int contactCount = 0;
        for (int i = 0; i < wheelCount; i++)
        {
            if (WheelHasContact(i))
            {
                contactCount++;
            }
        }

        if (contactCount == 0)
        {
            return;
        }

         // Get absolute steering value if steering exceeds threshold
        float steering = Math.AbsFloat(GetSteering());
        if (steering > PROTRACTION_STEERING_THRESHOLD)
        {
            return;
        }

        // Retrieve current velocity of vehicle, min speed check
        vector velocity = GetVelocity(this);
        if (velocity.LengthSq() <= (PROTRACTION_MIN_SPEED * PROTRACTION_MIN_SPEED))
        {
            return;
        }

        vector mat[4];
        dBodyGetWorldTransform(this, mat);

        // Calculate speed components in forward, right, and up directions
        float forwardSpeed = vector.Dot(velocity, mat[2]);
        float rightSpeed = vector.Dot(velocity, mat[0]);
        float upSpeed = vector.Dot(velocity, mat[1]);

        // Stabilize lateral movement if there is significant right speed
        if (Math.AbsFloat(rightSpeed) > 0.0001)
        {
            vector stabilizedVelocity = (mat[2] * forwardSpeed) + (mat[1] * upSpeed) + (mat[0] * rightSpeed * (1.0 - 0.05 * timeSlice));
            SetVelocity(this, stabilizedVelocity); // Set the new stabilized velocity
        }

        vector angularVelocity = dBodyGetAngularVelocity(this); // Get current angular velocity
        float yawSpeed = vector.Dot(angularVelocity, mat[1]);
        // Dampen yaw
        if (Math.AbsFloat(yawSpeed) > 0.0001)
        {
            float dampedYaw = yawSpeed * PROTRACTION_YAW_SCALE * timeSlice;
            vector stabilizedAngularVelocity = angularVelocity + (mat[1] * (dampedYaw - yawSpeed));
            dBodySetAngularVelocity(this, stabilizedAngularVelocity); // Set angular velocity
        }
    }

    // Apply on simulation (thanks dab)
    override void EOnSimulate(IEntity other, float dt)
    {
        super.EOnSimulate(other, dt);
        ApplyProTraction(dt);
    }
}
