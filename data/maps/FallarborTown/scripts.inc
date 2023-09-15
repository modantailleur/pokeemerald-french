FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "Il se passe quelque chose et je\n"
	.string "n'aime pas ça ! J'ai vu des\p"
	.string "personnages louches entrer et\n"
	.string "sortir de la maison du PROF.\p"
	.string "KOSMO…$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "Cette région est connue pour ses\n"
	.string "météores depuis l'Antiquité. On dit\p"
	.string "que MGUIDOEOR FALLS a été creusé\n"
	.string "par la chute d'une météorite il y a\p"
	.string "longtemps.$"

FallarborTown_Text_MyPreciousAzurill:
	.string "Voir! Regarde! C'est mon précieux\n"
	.string "AZURILL ! C'est lisse, lisse et\p"
	.string "moelleux aussi !$"

FallarborTown_Text_Azurill:
	.string "AZURILLE : Rooreelooo.$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "Avez-vous déjà défié ADRIANE, le\n"
	.string "LEADER du LAVARIDGE GYM ? Le\p"
	.string "grand-père de la jeune fille était\n"
	.string "célèbre. Il faisait partie des\p"
	.string "QUATRE ÉLITE de la LIGUE POKéMON à\n"
	.string "un moment donné. Cela ne me\p"
	.string "surprendrait pas de voir ADRIANE\n"
	.string "devenir une grande DRESSEUR à\p"
	.string "part entière.$"

FallarborTown_Text_BattleTentSign:
	.string "SITE DE LA TENTE DE BATAILLE DE\n"
	.string "FALLARBOR “ Que les plus grandes\p"
	.string "équipes se rassemblent ! ”$"

FallarborTown_Text_TownSign:
	.string "AUTEQUIA “ Une communauté agricole\n"
	.string "avec de petits jardins. ” $"

FallarborTown_Text_MoveTutorSign:
	.string "DÉPLACER LA MAISON DU TUTEUR “\n"
	.string "Nouveaux mouvements enseignés à\p"
	.string "POKéMON. ”$"
