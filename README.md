# OSDZ: Open Source DayZ Mods

Originally created by psyopgirl and provided as an example for education and utility purposes. 

Please feel free to implement these mods however you like, but liking and commenting on their various steam workshop pages is appreciated if you end up using them!

## Repository Contains:
### BetterDriving
BetterDriving is a lightweight, script-only DayZ mod that alters driving mechanics for ease of use.

1. Implements a control scheme similar to ArmA 2's vehicles, with W to accelerate and S to reverse.
2. Logical WASD-style vehicle controls for ease of use.
3. Automatic shifting for manual gearboxes based on RPM thresholds and throttle input.
4. Can be paired with ProTraction for a complete vehicle overhaul.
5. Smooth downshifts while decelerating, including neutral behavior at low speed.
6. Direction-change smoothing by routing forward ↔ reverse transitions through neutral and braking states.
7. Brake ramping when switching directions (0.5s ramp to full brake) for fine control and strong stopping power.
8. Reverse input that accelerates after deceleration; forward input cancels reverse.
9. Broad compatibility: affects any vehicle derived from `CarScript`, including most modded cars.

### ProTraction
ProTraction is a lightweight, script-only DayZ mod that prevents vehicles from sliding while driving and greatly increases overall traction.
1. Stops vehicles from spinning out, drifting, sliding, and more!
2. Prevents unexpected vehicle crashes and janky physics interactions.
3. Can be paired with BetterDriving for a full vehicle overhaul.
4. Unlike any other previous traction mod this does NOT affect surface grip or existing vanilla configs directly, rather it directly targets vehicle physics with a script overhaul.
5. Enhances driver control at mid-high speeds.
6. Does not affect ease of steering or regular driving mechanics outside of improving vehicle traction.
7. For nerds: clamps yaw movement range when a vehicle does not have an active movement input.
8. Broad compatibility: affects any vehicle derived from `CarScript`, including most modded cars.

### TemperatureZones
Source coming soon pending major update.

### BetterBoltAction
BetterBoltAction is a lightweight client-side mod that lets players cycle bolt-action rifles while remaining scoped.
1. Prevents forced exit of optics when cycling bolt action rifles.
2. Works for all items inherited from BoltActionRifle_Base, so should work for most/all modded bolt action weapons.
3. Does not affect other weapons or sight interactions.

###Yen Currency
Japanese Yen currency with wide trader/mod compatability. Designed for various Japan-themed servers and maps.
Contains a single-note stackable 1 Yen variant as well as a variant with many note denominations.
Based on Money Ruble by Designful.
