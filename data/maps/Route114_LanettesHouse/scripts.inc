Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "ANNGUIDOTE : Ah ! {PLAYER}{KUN} ! Je\n"
	.string "suis désolé que tout soit si\p"
	.string "encombré… Quand je suis absorbé par\n"
	.string "la recherche, les choses finissent\p"
	.string "ainsi… C'est embarrassant… S'il\n"
	.string "vous plaît, gardez cela secret en\p"
	.string "échange de cela.$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "Puis-je offrir des conseils sur mon\n"
	.string "système de stockage POKéMON ? Vous\p"
	.string "devez organiser vos BOÎTES de\n"
	.string "manière à pouvoir savoir quels\p"
	.string "POKéMON s'y trouvent.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "Ce sont les notes de recherche de\n"
	.string "ANNGUIDOTE. Il y a des informations\p"
	.string "sur les BOXES. Concevez des BOÎTES\n"
	.string "pouvant contenir 30 POKéMON\p"
	.string "chacune. Chaque DRESSEUR devrait\n"
	.string "être capable de stocker 420 POKéMON\p"
	.string "sur le système PC. Continuez à lire\n"
	.string "?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "Un système de marquage devrait être\n"
	.string "ajouté pour faciliter\p"
	.string "l'organisation de POKéMON. Le nom\n"
	.string "et le design du fond d'écran de\p"
	.string "chaque BOÎTE seront modifiés pour\n"
	.string "plaire au POKéMON stocké. Continuez\p"
	.string "à lire ?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "Lors du stockage d'un POKéMON, il\n"
	.string "doit être envoyé dans la BOX\p"
	.string "inspectée en dernier lieu. Si cette\n"
	.string "BOX est pleine, le POKéMON reçu est\p"
	.string "stocké dans la BOX suivante.\n"
	.string "Autrement dit, lorsqu'une BOX est\p"
	.string "examinée, elle est automatiquement\n"
	.string "sélectionnée comme la BOX vers\p"
	.string "laquelle les POKéMON sont envoyés.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} a fermé le carnet.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "Il y a un e-mail de quelqu'un sur\n"
	.string "le PC. “ … … … … … … … “ Votre\p"
	.string "système de stockage offre plus de\n"
	.string "commodité que le mien. “ Il possède\p"
	.string "de nombreuses fonctionnalités\n"
	.string "conviviales qui le rendent\p"
	.string "également amusant et utile. “ Cela\n"
	.string "me rend fier d’avoir contribué à\p"
	.string "son développement. “ J'espère que\n"
	.string "vous poursuivrez vos recherches sur\p"
	.string "les systèmes de stockage. “ De BILL\n"
	.string "… … … … … … … … ” $"
