.set LOCALID_DOCK, 1

SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
	.string "Umm… Si ça va ici, et ça va là-bas…\n"
	.string "Alors où va cette chose ? Et qu'en\p"
	.string "est-il de ce connard ? Aaargh ! Je\n"
	.string "n'arrive pas à comprendre ça !$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
	.string "Hein ? Salut, je suis DOCK. LE\n"
	.string "CAPT. POUPE m'a chargé de concevoir\p"
	.string "un ferry. Oh! Que là… Sont-ils des\n"
	.string "DEVON GOODS ? Mais, hmm… Cela ne\p"
	.string "suffira pas… LE CAPT. POUPE est\n"
	.string "parti quelque part. Il a dit qu'il\p"
	.string "avait du travail à faire. Puis-je\n"
	.string "vous demander d'aller trouver le\p"
	.string "CAPT. POUPE et de lui remettre ça\n"
	.string "?$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
	.string "DOCK : Où aurait pu aller le CAPT.\n"
	.string "POUPE ? Pourriez-vous aller trouver\p"
	.string "le CAPT. POUPE et lui remettre ce\n"
	.string "colis ?$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
	.string "DOCK : La construction navale est\n"
	.string "un art. Beaucoup de choses ne\p"
	.string "peuvent pas être comprises par de\n"
	.string "simples calculs. J'aurais vraiment\p"
	.string "besoin des conseils d'un vétéran\n"
	.string "qui connaît les mers…$"

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
	.string "QUAI : Salut ! M. MARCO nous\n"
	.string "rejoint pour nous apporter son\p"
	.string "aide. Grâce au marin vétéran, le\n"
	.string "ferry se met progressivement en\p"
	.string "place.$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
	.string "DOCK : Le ferry est enfin prêt ! Le\n"
	.string "nouveau S.S. TIDAL est une\p"
	.string "véritable merveille de technologie\n"
	.string "! Mais j’ai le sentiment que nous\p"
	.string "pouvons rendre quelque chose encore\n"
	.string "meilleur. Vous savez, la marche de\p"
	.string "la technologie n'a jamais de fin.$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.string "M. MARCO : Ah, {PLAYER}{KUN} ! Ça\n"
	.string "fait trop longtemps! Oui, depuis\p"
	.string "que je t'ai rencontré, ce vieux\n"
	.string "loup de mer se sent fringant ! J'ai\p"
	.string "donc décidé d'aider DOCK à\n"
	.string "fabriquer un ferry. Oui, après\p"
	.string "tout, un ferry pourrait transporter\n"
	.string "beaucoup de monde. Mais vous savez,\p"
	.string "ce DOCK est vraiment quelque chose\n"
	.string "de spécial. Avec son talent pour la\p"
	.string "technologie et mon expérience, je\n"
	.string "suis sûr que nous pouvons\p"
	.string "construire un grand navire, oui !$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "Les saisons, la météo, l'endroit où\n"
	.string "la lune se trouve dans le ciel… Ces\p"
	.string "conditions et d'autres encore font\n"
	.string "que la mer change d'expression.\p"
	.string "C'est exact! La mer est comme un\n"
	.string "être vivant !$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "J'ai très facilement le mal de mer.\n"
	.string "Alors je peux aider ici à la\p"
	.string "place.$"
