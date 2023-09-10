VictoryRoad_B1F_MapScripts::
	.byte 0

VictoryRoad_B1F_EventScript_Samuel::
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell::
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle::
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro:
	.string "L'idée que je me rapproche de la\n"
	.string "POKéMON LEAGUE… J'ai le trac…$"

VictoryRoad_B1F_Text_SamuelDefeat:
	.string "Je ne pouvais rien faire…$"

VictoryRoad_B1F_Text_SamuelPostBattle:
	.string "La LIGUE POKéMON est redevenue\n"
	.string "lointaine… Quelle déception…$"

VictoryRoad_B1F_Text_ShannonIntro:
	.string "Pour vous frayer un chemin dans la\n"
	.string "POKéMON LEAGUE, vous avez besoin de\p"
	.string "la confiance de votre POKéMON.$"

VictoryRoad_B1F_Text_ShannonDefeat:
	.string "Votre relation est basée sur une\n"
	.string "confiance solide.$"

VictoryRoad_B1F_Text_ShannonPostBattle:
	.string "En étant ensemble tout le temps, la\n"
	.string "confiance grandit entre POKéMON et\p"
	.string "les DRESSEURS.$"

VictoryRoad_B1F_Text_MichelleIntro:
	.string "Ce n'est pas le but. Ce n'est qu'un\n"
	.string "endroit sur le chemin de la LIGUE\p"
	.string "POKéMON.$"

VictoryRoad_B1F_Text_MichelleDefeat:
	.string "C'est comme ça !$"

VictoryRoad_B1F_Text_MichellePostBattle:
	.string "Vous vous en sortirez bien, c'est\n"
	.string "sûr ! Vos POKéMON sont tous\p"
	.string "impatients de partir !$"

VictoryRoad_B1F_Text_MitchellIntro:
	.string "Mes POKéMON sont cosmiquement\n"
	.string "impressionnants !$"

VictoryRoad_B1F_Text_MitchellDefeat:
	.string "Je n'ai jamais rencontré quelqu'un\n"
	.string "comme toi auparavant.$"

VictoryRoad_B1F_Text_MitchellPostBattle:
	.string "Même en dehors des combats, je\n"
	.string "ressens un pouvoir incroyable\p"
	.string "émanant de vous et de votre\n"
	.string "POKéMON.$"

VictoryRoad_B1F_Text_HalleIntro:
	.string "D'accord, pas besoin de vous\n"
	.string "relever ! Détendez-vous, allons-y\p"
	.string "doucement !$"

VictoryRoad_B1F_Text_HalleDefeat:
	.string "Waouh ! Merveilleux!$"

VictoryRoad_B1F_Text_HallePostBattle:
	.string "Bien sûr, c'est ROUTE VICTOIRE.\n"
	.string "Mais ce n’est pas si différent du\p"
	.string "chemin que vous avez emprunté\n"
	.string "jusqu’à présent. Essayez de\p"
	.string "profiter des choses jusqu'au bout\n"
	.string "!$"
