#define _ARMA_

class CfgPatches
{
	class BetterMilkyWay
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
			"DZ_Data",
			"DZ_Surfaces",
			"DZ_Scripts",
			"DZ_Worlds_Chernarusplus_World"
		};
	};
};
class CfgMods
{
	class BetterMilkyWay
	{
		dir = "BetterMilkyWay";
		picture = "";
		action = "";
		hideName = 0;
		hidePicture = 1;
		name = "BetterMilkyWay";
		credits = "Psyopgirl";
		author = "Psyopgirl";
		authorID = "0";
		version = "0.1";
		extra = 0;
		type = "mod";
	};
};
class CfgWorlds
{
	class CAWorld;
	class ChernarusPlus: CAWorld
	{
		spaceTexture0 = "BetterMilkyWay\data\tex\milkyway_left_co.paa";
		spaceTexture1 = "BetterMilkyWay\data\tex\milkyway_right_co.paa";
	};
};
