MossdeepCity_GameCorner_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

MossdeepCity_GameCorner_1F_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

MossdeepCity_GameCorner_1F_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_InfoMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_InfoMan2
	release
	end

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_OldMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_OldMan2
	release
	end


@ Everything below is leftover from RS
@ The house that was here in RS was moved to Sootopolis and replaced by the Game Corner
@ The text below is unused and duplicated in its replacement in Sootopolis City
@ And the BG Door event was moved inaccessibly into a wall

RS_MysteryEventsHouse_EventScript_Door::
	msgbox RS_MysteryEventsHouse_Text_DoorIsLocked, MSGBOX_SIGN
	end

RS_MysteryEventsHouse_Text_OldManGreeting:
	.string "Quand j'étais jeune, j'ai parcouru\n"
	.string "le monde en tant qu'DRESSEUR DE\p"
	.string "POKéMON. Maintenant que je suis\n"
	.string "devenu une vieille buse, mon seul\p"
	.string "amusement est de regarder les\n"
	.string "jeunes dresseurs se battre.$"

RS_MysteryEventsHouse_Text_DoorIsLocked:
	.string "La porte semble être verrouillée.$"

RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer:
	.string "Un FORMATTHIEUEUR nommé {STR_VAR_1}\n"
	.string "vient chez moi. Souhaitez-vous\p"
	.string "défier {STR_VAR_1} ?$"

RS_MysteryEventsHouse_Text_YouWontBattle:
	.string "Vous ne vous battrez pas ? Je suis\n"
	.string "déçu de ne pas pouvoir te voir\p"
	.string "combattre…$"

RS_MysteryEventsHouse_Text_KeepItToA3On3:
	.string "Oh, bien, bien ! Mais ma maison\n"
	.string "n'est pas si solide que ça. Puis-je\p"
	.string "vous demander de vous limiter à un\n"
	.string "match à 3 contre 3 ?$"

RS_MysteryEventsHouse_Text_SaveYourProgress:
	.string "Avant de vous battre, vous devriez\n"
	.string "sauvegarder votre progression.$"

RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch:
	.string "J'espère voir un bon match !$"

RS_MysteryEventsHouse_Text_BattleTie:
	.string "C’est donc devenu une impasse. Ce\n"
	.string "fut un match brillant dans lequel\p"
	.string "aucune des deux équipes n'a concédé\n"
	.string "le moindre pas !$"

RS_MysteryEventsHouse_Text_BattleWon:
	.string "C'était superlatif ! Eh bien,\n"
	.string "c'était comme me revoir dans ma\p"
	.string "jeunesse !$"

RS_MysteryEventsHouse_Text_BattleLost:
	.string "Ah, tant pis pour toi ! Mais\n"
	.string "c'était un bon match. J'espère que\p"
	.string "vous pourrez gagner la prochaine\n"
	.string "fois.$"
