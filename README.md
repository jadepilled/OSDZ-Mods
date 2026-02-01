#OSDZ: Open Source DayZ Mods

Originally created by psyopgirl and provided as an example for education and utility purposes. 

Please feel free to implement these mods however you like, but liking and commenting on their various steam workshop pages is appreciated if you end up using them!

##Repository Contains:
###BetterDriving
BetterDriving is a lightweight, script-only DayZ mod that alters driving mechanics for ease of use.
Implements a control scheme similar to ArmA 2's vehicles, with W to accelerate and S to reverse.
Logical WASD-style vehicle controls for ease of use.
Automatic shifting for manual gearboxes based on RPM thresholds and throttle input.
Can be paired with ProTraction for a complete vehicle overhaul.
Smooth downshifts while decelerating, including neutral behavior at low speed.
Direction-change smoothing by routing forward ↔ reverse transitions through neutral and braking states.
Brake ramping when switching directions (0.5s ramp to full brake) for fine control and strong stopping power.
Reverse input that accelerates after deceleration; forward input cancels reverse.
Broad compatibility: affects any vehicle derived from `CarScript`, including most modded cars.
###ProTraction
ProTraction is a lightweight, script-only DayZ mod that prevents vehicles from sliding while driving and greatly increases overall traction.
Stops vehicles from spinning out, drifting, sliding, and more!
Prevents unexpected vehicle crashes and janky physics interactions.
Can be paired with BetterDriving for a full vehicle overhaul.
Unlike any other previous traction mod this does NOT affect surface grip or existing vanilla configs directly, rather it directly targets vehicle physics with a script overhaul.
Enhances driver control at mid-high speeds.
Does not affect ease of steering or regular driving mechanics outside of improving vehicle traction.
For nerds: clamps yaw movement range when a vehicle does not have an active movement input.
Broad compatibility: affects any vehicle derived from `CarScript`, including most modded cars.
###TemperatureZones
Source coming soon pending major update.
###BetterBoltAction
BetterBoltAction is a lightweight client-side mod that lets players cycle bolt-action rifles while remaining scoped.
Prevents forced exit of optics when cycling bolt action rifles.
Works for all items inherited from BoltActionRifle_Base, so should work for most/all modded bolt action weapons.
Does not affect other weapons or sight interactions.
###Yen Currency
Japanese Yen currency with wide trader/mod compatability. Designed for various Japan-themed servers and maps.
Contains a single-note stackable 1 Yen variant as well as a variant with many note denominations.
Based on Money Ruble by Designful.
