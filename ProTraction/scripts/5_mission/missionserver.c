modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();
		if (GetGame().IsServer())
			Print("[ProTraction] Initialised ProTraction mod!");
	}
}