SlateportCity_SternsShipyard_2F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_2F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_2F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding:
	.string "Concevoir un grand navire revient\n"
	.string "plus à construire un grand bâtiment\p"
	.string "qu'à assembler un véhicule de\n"
	.string "transport.$"

SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy:
	.string "Ne trouvez-vous pas étrange qu'un\n"
	.string "navire fait de fer lourd flotte ?\p"
	.string "Il flotte grâce à un principe\n"
	.string "appelé flottabilité.$"
