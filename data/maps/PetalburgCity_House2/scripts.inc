PetalburgCity_House2_MapScripts::
	.byte 0

PetalburgCity_House2_EventScript_Woman::
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_SchoolKid::
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	end

PetalburgCity_House2_Text_NormanBecameGymLeader:
	.string "NORMAN est devenu le nouveau GYM\n"
	.string "LEADER de notre ville. Je pense\p"
	.string "qu'il a appelé sa famille de\n"
	.string "quelque part loin.$"

PetalburgCity_House2_Text_BattledNormanOnce:
	.string "J'ai affronté NORMAN une fois, mais\n"
	.string "ouf, il était bien trop fort.\p"
	.string "Comment pourrais-je le dire ? J'ai\n"
	.string "juste l'impression qu'il vit pour\p"
	.string "POKéMON.$"
