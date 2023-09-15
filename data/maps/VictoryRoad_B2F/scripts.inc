VictoryRoad_B2F_MapScripts::
	.byte 0

VictoryRoad_B2F_EventScript_Vito::
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline::
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix::
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne::
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro:
	.string "Je me suis entraîné avec toute ma\n"
	.string "famille, chacun de nous ! Je ne\p"
	.string "perds contre personne !$"

VictoryRoad_B2F_Text_VitoDefeat:
	.string "Mieux que ma famille ?! Est-ce\n"
	.string "possible ?!$"

VictoryRoad_B2F_Text_VitoPostBattle:
	.string "J'étais meilleur que tous les\n"
	.string "membres de ma famille. Je n'ai\p"
	.string "jamais perdu auparavant… J'ai perdu\n"
	.string "confiance en moi… Peut-être que je\p"
	.string "rentrerai à la maison…$"

VictoryRoad_B2F_Text_OwenIntro:
	.string "J'avais entendu dire qu'il y avait\n"
	.string "un petit enfant dur dans les\p"
	.string "parages. Est-ce qu'ils veulent dire\n"
	.string "toi ?$"

VictoryRoad_B2F_Text_OwenDefeat:
	.string "La petite crevette est coriace !$"

VictoryRoad_B2F_Text_OwenPostBattle:
	.string "D'après les rumeurs que j'ai\n"
	.string "entendues, ce petit enfant coriace\p"
	.string "vient de PGUIDOALBURG CITY.$"

VictoryRoad_B2F_Text_CarolineIntro:
	.string "Tu dois être un peu fatigué.$"

VictoryRoad_B2F_Text_CarolineDefeat:
	.string "Aucun signe de fatigue du tout !$"

VictoryRoad_B2F_Text_CarolinePostBattle:
	.string "ROUTE VICTOIRE et la POKéMON LEAGUE\n"
	.string "sont des défis longs et épuisants.\p"
	.string "Attention à la fatigue!$"

VictoryRoad_B2F_Text_JulieIntro:
	.string "Vous ne devriez pas faire preuve de\n"
	.string "complaisance simplement parce que\p"
	.string "vous avez beaucoup de BADGES GYM.\n"
	.string "Il y aura toujours quelqu'un qui\p"
	.string "sera meilleur que toi !$"

VictoryRoad_B2F_Text_JulieDefeat:
	.string "Tu es meilleur que moi !$"

VictoryRoad_B2F_Text_JuliePostBattle:
	.string "Contemplez vos BADGES collectés et\n"
	.string "souvenez-vous des DRESSEURS\p"
	.string "que vous avez affrontés.$"

VictoryRoad_B2F_Text_FelixIntro:
	.string "Je suis arrivé jusqu'ici, mais la\n"
	.string "tension me donne d'horribles\p"
	.string "douleurs au ventre…$"

VictoryRoad_B2F_Text_FelixDefeat:
	.string "Ooh… ça fait mal…$"

VictoryRoad_B2F_Text_FelixPostBattle:
	.string "Je ne peux m'empêcher d'être tout\n"
	.string "tendu sachant que j'approche de la\p"
	.string "POKéMON LEAGUE. C'est tout ce que\n"
	.string "je peux faire pour feindre le\p"
	.string "calme.$"

VictoryRoad_B2F_Text_DianneIntro:
	.string "L’élite parmi l’élite se rassemble\n"
	.string "dans cette grotte. Comment le\p"
	.string "trouvez-vous ?$"

VictoryRoad_B2F_Text_DianneDefeat:
	.string "Pas du tout secoué !$"

VictoryRoad_B2F_Text_DiannePostBattle:
	.string "Tu as du cran ! J'aime ça!\n"
	.string "Continuez comme ça !$"
