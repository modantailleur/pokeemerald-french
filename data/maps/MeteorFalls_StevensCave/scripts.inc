.set LOCALID_STEVEN, 1

MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "PIERRE : Oh, wow, {PLAYER}{KUN}. Je\n"
	.string "suis étonné que vous sachiez où me\p"
	.string "trouver. Est-ce que, euh… vous me\n"
	.string "considérez peut-être comme un\p"
	.string "simple maniaque du rock ? Non, ça\n"
	.string "ne peut pas être vrai. Nous nous\p"
	.string "sommes battus côte à côte au CENTRE\n"
	.string "SPATIAL SOOTOPOLIS. Vous devriez\p"
	.string "avoir une très bonne idée de à quel\n"
	.string "point je suis bon. D'accord,\p"
	.string "{PLAYER}{KUN}, si vous comptez\n"
	.string "relever un défi sérieux,\p"
	.string "attendez-vous au pire !$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "Toi… je ne pensais pas que tu\n"
	.string "deviendrais si fort…$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "PIERRE : À bien y penser, depuis\n"
	.string "que nos chemins se sont croisés\p"
	.string "pour la première fois à GROTTE\n"
	.string "GRANITE à DEWFORD, j'ai eu ce\p"
	.string "sentiment. Je pensais que tu\n"
	.string "finirais par devenir le CHAMPION.\p"
	.string "Mes prédictions se réalisent\n"
	.string "généralement. Et où irez-vous à\p"
	.string "partir d’ici ? … … … … … … … … … …\n"
	.string "… Fufufu, même moi, je ne pourrais\p"
	.string "pas te le dire.$"
