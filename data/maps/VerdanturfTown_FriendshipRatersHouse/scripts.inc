VerdanturfTown_FriendshipRatersHouse_MapScripts::
	.byte 0

VerdanturfTown_FriendshipRatersHouse_EventScript_FriendshipRater::
	lock
	faceplayer
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou
	case FRIENDSHIP_1_TO_49, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary
	case FRIENDSHIP_50_TO_99, VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou
	case FRIENDSHIP_100_TO_149, VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou
	case FRIENDSHIP_150_TO_199, VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot
	case FRIENDSHIP_200_TO_254, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy
	case FRIENDSHIP_MAX, VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryWary, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou:
	.string "Montre-moi ton POKéMON. Je vais\n"
	.string "vérifier à quel point il\p"
	.string "t'apprécie. Oh. Votre POKéMON…$"

VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou:
	.string "Il vous adore. Il ne peut plus\n"
	.string "t'aimer. Je suis même heureux de le\p"
	.string "voir.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy:
	.string "Il semble être très heureux. Il est\n"
	.string "évident que vous lui plaisez\p"
	.string "beaucoup.$"

VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot:
	.string "Il vous aime beaucoup. Il semble\n"
	.string "vouloir être un peu dorloté.$"

VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou:
	.string "On s'habitue à toi. Il semble\n"
	.string "croire en toi.$"

VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou:
	.string "Vous n'êtes pas encore très\n"
	.string "habitué. Il ne vous aime ni ne vous\p"
	.string "déteste.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryWary:
	.string "C'est très prudent. Il a une\n"
	.string "méchanceté effrayante dans ses\p"
	.string "yeux. Il ne t'aime pas beaucoup du\n"
	.string "tout.$"

VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou:
	.string "C'est un peu difficile à dire pour\n"
	.string "moi… Votre POKéMON vous déteste\p"
	.string "tout simplement. Cela ne vous\n"
	.string "met-il pas mal à l'aise ?$"

VerdanturfTown_FriendshipRatersHouse_Text_Pikachu:
	.string "Pikachu : Pika Pika ! $"
