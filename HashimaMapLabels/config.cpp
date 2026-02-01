////////////////////////////////////////////////////////////////////////////////////  
//                ____ ____ ____ ____ ___ ____ ___     ___  _   _                 //  
//                |    |__/ |___ |__|  |  |___ |  \    |__]  \_/                  //
//                |___ |  \ |___ |  |  |  |___ |__/    |__]   |                   //
//                                                                                //
//                                                                                //
//     ██▓███    ██████ ▓██   ██▓ ▒█████   ██▓███    ▄████  ██▓ ██▀███   ██▓      //
//   ▓██░  ██▒▒██    ▒  ▒██  ██▒▒██▒  ██▒▓██░  ██▒ ██▒ ▀█▒▓██▒▓██ ▒ ██▒▓██▒       //
//   ▓██░ ██▓▒░ ▓██▄     ▒██ ██░▒██░  ██▒▓██░ ██▓▒▒██░▄▄▄░▒██▒▓██ ░▄█ ▒▒██░       //
//   ▒██▄█▓▒ ▒  ▒   ██▒  ░ ▐██▓░▒██   ██░▒██▄█▓▒ ▒░▓█  ██▓░██░▒██▀▀█▄  ▒██░       //
//   ▒██▒ ░  ░▒██████▒▒  ░ ██▒▓░░ ████▓▒░▒██▒ ░  ░░▒▓███▀▒░██░░██▓ ▒██▒░██████▒   //
//   ▒▓▒░ ░  ░▒ ▒▓▒ ▒ ░   ██▒▒▒ ░ ▒░▒░▒░ ▒▓▒░ ░  ░ ░▒   ▒ ░▓  ░ ▒▓ ░▒▓░░ ▒░▓  ░   //
//   ░▒ ░     ░ ░▒  ░ ░ ▓██ ░▒░   ░ ▒ ▒░ ░▒ ░       ░   ░  ▒ ░  ░▒ ░ ▒░░ ░ ▒  ░   //
//   ░░       ░  ░  ░   ▒ ▒ ░░  ░ ░ ░ ▒  ░░       ░ ░   ░  ▒ ░  ░░   ░   ░ ░      //
//                  ░   ░ ░         ░ ░                 ░  ░     ░         ░  ░   //
//                      ░ ░                                                       //
//                                                                                //
//                                 ____ ____ ____                                 //
//                                 |___ |  | |__/                                 //
//                                 |    |__| |  \                                 //
//                                                                                //           //                                                                                //
//    ██▓███    ██████ ▓██   ██▓ ▒█████   ██▓███    ██████        ▄████   ▄████   //
//   ▓██░  ██▒▒██    ▒  ▒██  ██▒▒██▒  ██▒▓██░  ██▒▒██    ▒       ██▒ ▀█▒ ██▒ ▀█▒  //
//   ▓██░ ██▓▒░ ▓██▄     ▒██ ██░▒██░  ██▒▓██░ ██▓▒░ ▓██▄        ▒██░▄▄▄░▒██░▄▄▄░  //
//   ▒██▄█▓▒ ▒  ▒   ██▒  ░ ▐██▓░▒██   ██░▒██▄█▓▒ ▒  ▒   ██▒     ░▓█  ██▓░▓█  ██▓  //
//   ▒██▒ ░  ░▒██████▒▒  ░ ██▒▓░░ ████▓▒░▒██▒ ░  ░▒██████▒▒ ██▓ ░▒▓███▀▒░▒▓███▀▒  //
//   ▒▓▒░ ░  ░▒ ▒▓▒ ▒ ░   ██▒▒▒ ░ ▒░▒░▒░ ▒▓▒░ ░  ░▒ ▒▓▒ ▒ ░ ▒▓▒  ░▒   ▒  ░▒   ▒   //
//   ░▒ ░     ░ ░▒  ░ ░ ▓██ ░▒░   ░ ▒ ▒░ ░▒ ░     ░ ░▒  ░ ░ ░▒    ░   ░   ░   ░   //
//   ░░       ░  ░  ░   ▒ ▒ ░░  ░ ░ ░ ▒  ░░       ░  ░  ░   ░   ░ ░   ░ ░ ░   ░   //
//                  ░   ░ ░         ░ ░                 ░    ░        ░       ░   //
//                      ░ ░                                  ░                    //
//                                                                                //
//                                                                                //
////////////////////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class HashimaWorldLabels
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
			"DZ_Data",
			"DZ_Surfaces",
			"HashimaWorld",
			"Hashima",
			"DZ_Worlds_Chernarusplus_World"
		};
	};
};
class CfgLocationTypes
{
	class Name
	{
		name = "keypoint";
		drawStyle = "name";
		texture = "#(argb,1,1,1)color(1,1,1,1)";
		color[] = {1,1,1,1};
		size = 0;
		font = "gui/fonts/sdf_notosanscjk-light28";
		textSize = 0.04;
		shadow = 1;
		importance = 1;
	};
	class NameIcon
	{
		name = "keypoint";
		drawStyle = "icon";
		texture = "#(argb,1,1,1)color(1,1,1,1)";
		color[] = {0,0,0,1};
		size = 0;
		font = "gui/fonts/sdf_notosanscjk-light28";
		textSize = 0.02;
		shadow = 1;
		importance = 1;
	};
	class Capital: Name
	{
		color[] = {0,0,0,1};
		textSize = 0.05;
		importance = 7;
	};
	class City: Name
	{
		color[] = {1,1,1,1};
		textSize = 0.04;
		importance = 6;
	};
	class Village: Name
	{
		color[] = {0.15,0.15,0,1};
		textSize = 0.03;
		importance = 5;
	};
	class Complex: Name
	{
		color[] = {0,0,0,1};
		textSize = 0.03;
		importance = 4;
	};
	class Lab: Name
	{
		color[] = {1,0,0,1};
		textSize = 0.04;
		importance = 7;
	};
};
class CfgWorlds
{
	class Names;
	class CAWorld;
	class Hashima: CAWorld
	{
		class Names: Names
		{
			class label_bridge_west
			{
				name="West New Hashima Bridge";
				position[]={2159.63,2397.71};
				type="Village";
			};
			class label_bridge_east
			{
				name="East New Hashima Bridge";
				position[]={2844.68,2630.21};
				type="Village";
			};
			class label_West_Hashima
			{
				name="West Hashima";
				position[]={1473.98,1031.87};
				type="Capital";
			};
			class label_East_Hashima
			{
				name="East Hashima";
				position[]={4111.33,2632.13};
				type="Capital";
			};
			class label_Obake
			{
				name="Obake";
				position[]={3575.38,1016.31};
				type="Capital";
			};
			class label_Away
			{
				name="Away";
				position[]={1236.7,4193.4};
				type="Capital";
			};
			class label_New_Hashima
			{
				name="New Hashima";
				position[]={2184.75,2550.90};
				type="Capital";
			};
			class label_Path_North
			{
				name="Path (North)";
				position[]={1581.62,3481};
				type="Village";
			};
			class label_Path_South
			{
				name="Path (South)";
				position[]={3177.96,1868.79};
				type="Village";
			};
			class label_Okubo_Airport
			{
				name="Okubo Airport";
				position[]={3422.54,3422.78};
				type="City";
			};
			class label_Yasuo_City
			{
				name="Yasuo City";
				position[]={3505.79,2827.26};
				type="City";
			};	
			class label_New_Hashima_City
			{
				name="New Hashima City";
				position[]={2499.34,2556.94};
				type="City";
			};	
			class label_Kodama_City
			{
				name="Kodama City";
				position[]={4258.85,1005.35};
				type="City";
			};
			class label_Haruki_Castle
			{
				name="Haruki Castle";
				position[]={1836.18,2380.51};
				type="City";
			};	
			class label_Haruki_City
			{
				name="Haruki City";
				position[]={1620.41,2208.05};
				type="City";
			};	
			class label_Eiko_Stadium
			{
				name="Eiko Stadium";
				position[]={897,1941.4};
				type="City";
			};
			class label_Tsukomogami_Complex
			{
				name="Tsukomogami Complex";
				position[]={2198.033,2882.90};
				type="City";
			};	
			class label_Shinkai_Complex
			{
				name="Shinkai Complex";
				position[]={1019.14,4105.68};
				type="City";
			};
			class label_POWWWS_PEST
			{
				name="POWWWS PEST";
				position[]={897.56,1744.93};
				type="Lab";
			};
			class label_POWWWS_BIOS
			{
				name="POWWWS BIOS";
				position[]={4100.18,760.47};
				type="Lab";
			};	
			class label_POWWWS_NECRO
			{
				name="POWWWS NECRO";
				position[]={440.43,4550.64};
				type="Lab";
			};			
		};
	};
};