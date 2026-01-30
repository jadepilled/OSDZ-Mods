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

        //Vector normalisation + get
        vector forward = GetDirection();
        vector up = GetDirectionUp();
        forward.Normalize();
        up.Normalize();

        vector right = forward * up;
        right.Normalize();

        // Calculate speed components in forward, right, and up directions
        float forwardSpeed = vector.Dot(velocity, forward);
        float rightSpeed = vector.Dot(velocity, right);
        float upSpeed = vector.Dot(velocity, up);

        // Stabilize lateral movement if there is significant right speed
        if (Math.AbsFloat(rightSpeed) > 0.0001)
        {
            vector stabilizedVelocity = (forward * forwardSpeed) + (up * upSpeed);
            SetVelocity(this, stabilizedVelocity); // Set the new stabilized velocity
        }

        vector angularVelocity = dBodyGetAngularVelocity(this); // Get current angular velocity
        float yawSpeed = vector.Dot(angularVelocity, up);
        // Dampen yaw if sideward motion is present
        if (Math.AbsFloat(yawSpeed) > 0.0001)
        {
            float dampedYaw = yawSpeed * PROTRACTION_YAW_SCALE;
            vector stabilizedAngularVelocity = angularVelocity + (up * (dampedYaw - yawSpeed));
            dBodySetAngularVelocity(this, stabilizedAngularVelocity); // Set angular velocity
        }
    }

    // Apply on post-simulation (thanks dab)
    override void EOnPostSimulate(IEntity other, float timeSlice)
    {
        super.EOnPostSimulate(other, timeSlice);
        ApplyProTraction(timeSlice);
    }
}