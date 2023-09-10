MtPyre_4F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_5F_EventScript_Atsushi::
	trainerbattle_single TRAINER_ATSUSHI, MtPyre_5F_Text_AtsushiIntro, MtPyre_5F_Text_AtsushiDefeat
	msgbox MtPyre_5F_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_5F_Text_AtsushiIntro:
	.string "PROF.… S'il vous plaît, surveillez\n"
	.string "mes progrès !$"

MtPyre_5F_Text_AtsushiDefeat:
	.string "PROF.… S'il vous plaît,\n"
	.string "pardonnez-moi !$"

MtPyre_5F_Text_AtsushiPostBattle:
	.string "Jusqu'à ce que je m'améliore, mon\n"
	.string "PROF., qui repose ici, ne trouvera\p"
	.string "jamais la vraie paix…$"
