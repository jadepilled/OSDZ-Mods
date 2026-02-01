class CfgPatches
{
	class NoVoiceMuffle
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Characters",
			"DZ_Characters_Masks",
			"DZ_Characters_Headgear",
			"DZ_Scripts"
		};
	};
};
class CfgMods
{
	class NoVoiceMuffle
	{
		dir="NoVoiceMuffle";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="No Voice Muffle";
		author="psyopgirl";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"Game",
			"world"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"NoVoiceMuffle/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"NoVoiceMuffle/scripts/4_world"
				};
			};
		};
	};
};
class CfgNonAIVehicles
{
	class StaticObject;
};
