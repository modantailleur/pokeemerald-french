LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition:
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle::
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords::
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries::
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest::
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks:
	.string "Oh, mon Dieu! Vous voyagez seul ?\n"
	.string "Mais tu es si jeune ! Bien pour\p"
	.string "vous! Je suis sûr que mes enfants\n"
	.string "pourraient apprendre une chose ou\p"
	.string "deux de vous ! Moi? Je suis un\n"
	.string "maître de {POKEBLOCK}S. Si je deviens un\p"
	.string "peu sérieux, eh bien, je peux\n"
	.string "concocter de superbes {POKEBLOCK} S.\p"
	.string "Souhaitez-vous apprendre de moi, un\n"
	.string "maître des {POKEBLOCK}S ?$"

LilycoveCity_House3_Text_OhAreYouSure:
	.string "Oh? Es-tu sûr? Vous ne devriez pas\n"
	.string "toujours essayer de tout faire\p"
	.string "vous-même, ma chère !$"

LilycoveCity_House3_Text_ExplainPokeblocks:
	.string "Oh super! Vous êtes une âme\n"
	.string "intelligente ! C'est un peu long,\p"
	.string "alors écoutez ! Es-tu prêt? Si vous\n"
	.string "regardez les {POKEBLOCK}S, vous devriez\p"
	.string "voir qu'ils sont évalués en\n"
	.string "fonction de ce qu'ils ressentent.\p"
	.string "Plus la note de sensation est\n"
	.string "basse, mieux c'est. N'oubliez pas\p"
	.string "ça ! Un bon {POKEBLOCK} a une faible\n"
	.string "note de sensation et un niveau\p"
	.string "élevé. Un POKéMON peut également\n"
	.string "manger plus de bons {POKEBLOCK} que les\p"
	.string "Pokémon ordinaires. Et c'est\n"
	.string "important. Si vous souhaitez créer\p"
	.string "des {POKEBLOCK} S lisses, utilisez\n"
	.string "différents types de BAIES. Ne soyez\p"
	.string "pas avare : les types de BAIES\n"
	.string "affectent la douceur des {POKEBLOCK} S.\p"
	.string "Et autre chose. Plus il y a de\n"
	.string "personnes qui mélangent des BAIES,\p"
	.string "plus les {POKEBLOCK}S sont doux. C'est\n"
	.string "pourquoi vous devriez parler à\p"
	.string "d'autres personnes et créer des\n"
	.string "{POKEBLOCK} S ensemble. C'est à peu près\p"
	.string "tout ce que vous devez savoir pour\n"
	.string "créer de bons {POKEBLOCK}S. Si tout le\p"
	.string "monde avait des POKéMON qu'ils\n"
	.string "aiment, des {POKEBLOCK} lisses et une\p"
	.string "famille aimante, le monde serait\n"
	.string "plus heureux. N'abandonne pas,\p"
	.string "chérie !$"

LilycoveCity_House3_Text_HappyToHaveQuadruplets:
	.string "Lorsque ma femme a donné naissance\n"
	.string "à des quadruplés, vous pariez que\p"
	.string "j'ai été choqué. Mais maintenant,\n"
	.string "les voir jouer ensemble, ça me rend\p"
	.string "heureux.$"

LilycoveCity_House3_Text_GoingToWinMultiBattles:
	.string "Nous avons des BATAILLES MULTIPLES,\n"
	.string "mais je sais que je vais gagner.$"

LilycoveCity_House3_Text_LikeMixingAtRecordCorner:
	.string "Nous aimons mixer des trucs au\n"
	.string "RECORD CORNER. Mais qu’est-ce qui\p"
	.string "se mélange ?$"

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender:
	.string "Nous allons faire de super {POKEBLOCK}S\n"
	.string "avec un BERRY BLENDER !$"

LilycoveCity_House3_Text_GoingToEnterContest:
	.string "Je veux me vanter de la solidité de\n"
	.string "mon POKéMON, nous allons donc\p"
	.string "participer à un CONCOURS ensemble.$"
