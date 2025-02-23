const u8 gEasyChatWord_Meets[] = _("SE RENCONTRE");
const u8 gEasyChatWord_Concede[] = _("CONCÉDER");
const u8 gEasyChatWord_Give[] = _("DONNER");
const u8 gEasyChatWord_Gives[] = _("DONNE");
const u8 gEasyChatWord_Played[] = _("JOUÉ");
const u8 gEasyChatWord_Plays[] = _("PIÈCES");
const u8 gEasyChatWord_Collect[] = _("COLLECTER");
const u8 gEasyChatWord_Walking[] = _("MARCHE");
const u8 gEasyChatWord_Walks[] = _("DES PROMENADES");
const u8 gEasyChatWord_Says[] = _("DIT");
const u8 gEasyChatWord_Went[] = _("EST ALLÉ");
const u8 gEasyChatWord_Said[] = _("DIT");
const u8 gEasyChatWord_WakeUp[] = _("RÉVEILLEZ-VOUS");
const u8 gEasyChatWord_WakesUp[] = _("SE RÉVEILLE");
const u8 gEasyChatWord_Angers[] = _("ANGERS");
const u8 gEasyChatWord_Teach[] = _("ENSEIGNER");
const u8 gEasyChatWord_Teaches[] = _("ENSEIGNE");
const u8 gEasyChatWord_Please[] = _("S'IL TE PLAÎT");
const u8 gEasyChatWord_Learn[] = _("APPRENDRE");
const u8 gEasyChatWord_Change[] = _("CHANGEMENT");
const u8 gEasyChatWord_Story[] = _("HISTOIRE");
const u8 gEasyChatWord_Trust[] = _("CONFIANCE");
const u8 gEasyChatWord_Lavish[] = _("SOMPTUEUX");
const u8 gEasyChatWord_Listens[] = _("ECOUTE");
const u8 gEasyChatWord_Hearing[] = _("AUDIENCE");
const u8 gEasyChatWord_Trains[] = _("LES TRAINS");
const u8 gEasyChatWord_Choose[] = _("CHOISIR");
const u8 gEasyChatWord_Come[] = _("VIENS");
const u8 gEasyChatWord_Came[] = _("EST VENU");
const u8 gEasyChatWord_Search[] = _("RECHERCHE");
const u8 gEasyChatWord_Make[] = _("FAIRE");
const u8 gEasyChatWord_Cause[] = _("CAUSE");
const u8 gEasyChatWord_Know[] = _("SAVOIR");
const u8 gEasyChatWord_Knows[] = _("SAIT");
const u8 gEasyChatWord_Refuse[] = _("REFUSER");
const u8 gEasyChatWord_Stores[] = _("MAGASINS");
const u8 gEasyChatWord_Brag[] = _("SE VANTER");
const u8 gEasyChatWord_Ignorant[] = _("IGNORANT");
const u8 gEasyChatWord_Thinks[] = _("PENSE");
const u8 gEasyChatWord_Believe[] = _("CROIRE");
const u8 gEasyChatWord_Slide[] = _("GLISSER");
const u8 gEasyChatWord_Eats[] = _("MANGE");
const u8 gEasyChatWord_Use[] = _("UTILISER");
const u8 gEasyChatWord_Uses[] = _("LES USAGES");
const u8 gEasyChatWord_Using[] = _("EN UTILISANT");
const u8 gEasyChatWord_Couldnt[] = _("NE POUVAIT PAS");
const u8 gEasyChatWord_Capable[] = _("CAPABLE");
const u8 gEasyChatWord_Disappear[] = _("DISPARAÎTRE");
const u8 gEasyChatWord_Appear[] = _("APPARAÎTRE");
const u8 gEasyChatWord_Throw[] = _("LANCER");
const u8 gEasyChatWord_Worry[] = _("INQUIÉTUDE");
const u8 gEasyChatWord_Slept[] = _("DORMI");
const u8 gEasyChatWord_Sleep[] = _("DORMIR");
const u8 gEasyChatWord_Release[] = _("LIBÉRER");
const u8 gEasyChatWord_Drinks[] = _("BOISSONS");
const u8 gEasyChatWord_Runs[] = _("COURSES");
const u8 gEasyChatWord_Run[] = _("FUIR");
const u8 gEasyChatWord_Works[] = _("TRAVAUX");
const u8 gEasyChatWord_Working[] = _("FONCTIONNEMENT");
const u8 gEasyChatWord_Talking[] = _("PARLER");
const u8 gEasyChatWord_Talk[] = _("PARLER");
const u8 gEasyChatWord_Sink[] = _("COULER");
const u8 gEasyChatWord_Smack[] = _("CLAQUE");
const u8 gEasyChatWord_Pretend[] = _("PRÉTENDRE");
const u8 gEasyChatWord_Praise[] = _("LOUER");
const u8 gEasyChatWord_Overdo[] = _("EXAGÉRER");
const u8 gEasyChatWord_Show[] = _("MONTRER");
const u8 gEasyChatWord_Looks[] = _("REGARDS");
const u8 gEasyChatWord_Sees[] = _("VOIT");
const u8 gEasyChatWord_Seek[] = _("CHERCHER");
const u8 gEasyChatWord_Own[] = _("PROPRE");
const u8 gEasyChatWord_Take[] = _("PRENDRE");
const u8 gEasyChatWord_Allow[] = _("PERMETTRE");
const u8 gEasyChatWord_Forget[] = _("OUBLIER");
const u8 gEasyChatWord_Forgets[] = _("OUBLIE");
const u8 gEasyChatWord_Appears[] = _("APPARAÎT");
const u8 gEasyChatWord_Faint[] = _("S'ÉVANOUIR");
const u8 gEasyChatWord_Fainted[] = _("ÉVANOUI");

const struct EasyChatWordInfo gEasyChatGroup_Actions[] = {
    [EC_INDEX(EC_WORD_MEETS)] =
    {
        .text = gEasyChatWord_Meets,
        .alphabeticalOrder = 72,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CONCEDE)] =
    {
        .text = gEasyChatWord_Concede,
        .alphabeticalOrder = 14,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIVE)] =
    {
        .text = gEasyChatWord_Give,
        .alphabeticalOrder = 48,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIVES)] =
    {
        .text = gEasyChatWord_Gives,
        .alphabeticalOrder = 75,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PLAYED)] =
    {
        .text = gEasyChatWord_Played,
        .alphabeticalOrder = 39,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PLAYS)] =
    {
        .text = gEasyChatWord_Plays,
        .alphabeticalOrder = 36,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COLLECT)] =
    {
        .text = gEasyChatWord_Collect,
        .alphabeticalOrder = 28,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WALKING)] =
    {
        .text = gEasyChatWord_Walking,
        .alphabeticalOrder = 46,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WALKS)] =
    {
        .text = gEasyChatWord_Walks,
        .alphabeticalOrder = 31,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SAYS)] =
    {
        .text = gEasyChatWord_Says,
        .alphabeticalOrder = 19,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WENT)] =
    {
        .text = gEasyChatWord_Went,
        .alphabeticalOrder = 26,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SAID)] =
    {
        .text = gEasyChatWord_Said,
        .alphabeticalOrder = 6,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAKE_UP)] =
    {
        .text = gEasyChatWord_WakeUp,
        .alphabeticalOrder = 27,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAKES_UP)] =
    {
        .text = gEasyChatWord_WakesUp,
        .alphabeticalOrder = 1,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ANGERS)] =
    {
        .text = gEasyChatWord_Angers,
        .alphabeticalOrder = 45,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TEACH)] =
    {
        .text = gEasyChatWord_Teach,
        .alphabeticalOrder = 47,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TEACHES)] =
    {
        .text = gEasyChatWord_Teaches,
        .alphabeticalOrder = 54,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PLEASE)] =
    {
        .text = gEasyChatWord_Please,
        .alphabeticalOrder = 41,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEARN)] =
    {
        .text = gEasyChatWord_Learn,
        .alphabeticalOrder = 76,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHANGE)] =
    {
        .text = gEasyChatWord_Change,
        .alphabeticalOrder = 77,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STORY)] =
    {
        .text = gEasyChatWord_Story,
        .alphabeticalOrder = 73,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRUST)] =
    {
        .text = gEasyChatWord_Trust,
        .alphabeticalOrder = 74,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LAVISH)] =
    {
        .text = gEasyChatWord_Lavish,
        .alphabeticalOrder = 2,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LISTENS)] =
    {
        .text = gEasyChatWord_Listens,
        .alphabeticalOrder = 3,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEARING)] =
    {
        .text = gEasyChatWord_Hearing,
        .alphabeticalOrder = 24,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRAINS)] =
    {
        .text = gEasyChatWord_Trains,
        .alphabeticalOrder = 37,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHOOSE)] =
    {
        .text = gEasyChatWord_Choose,
        .alphabeticalOrder = 32,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COME)] =
    {
        .text = gEasyChatWord_Come,
        .alphabeticalOrder = 33,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAME)] =
    {
        .text = gEasyChatWord_Came,
        .alphabeticalOrder = 22,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEARCH)] =
    {
        .text = gEasyChatWord_Search,
        .alphabeticalOrder = 18,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MAKE)] =
    {
        .text = gEasyChatWord_Make,
        .alphabeticalOrder = 23,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAUSE)] =
    {
        .text = gEasyChatWord_Cause,
        .alphabeticalOrder = 67,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KNOW)] =
    {
        .text = gEasyChatWord_Know,
        .alphabeticalOrder = 30,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KNOWS)] =
    {
        .text = gEasyChatWord_Knows,
        .alphabeticalOrder = 0,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_REFUSE)] =
    {
        .text = gEasyChatWord_Refuse,
        .alphabeticalOrder = 65,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STORES)] =
    {
        .text = gEasyChatWord_Stores,
        .alphabeticalOrder = 70,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BRAG)] =
    {
        .text = gEasyChatWord_Brag,
        .alphabeticalOrder = 4,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IGNORANT)] =
    {
        .text = gEasyChatWord_Ignorant,
        .alphabeticalOrder = 5,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THINKS)] =
    {
        .text = gEasyChatWord_Thinks,
        .alphabeticalOrder = 17,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BELIEVE)] =
    {
        .text = gEasyChatWord_Believe,
        .alphabeticalOrder = 64,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SLIDE)] =
    {
        .text = gEasyChatWord_Slide,
        .alphabeticalOrder = 63,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EATS)] =
    {
        .text = gEasyChatWord_Eats,
        .alphabeticalOrder = 34,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_USE)] =
    {
        .text = gEasyChatWord_Use,
        .alphabeticalOrder = 53,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_USES)] =
    {
        .text = gEasyChatWord_Uses,
        .alphabeticalOrder = 56,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_USING)] =
    {
        .text = gEasyChatWord_Using,
        .alphabeticalOrder = 55,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COULDN_T)] =
    {
        .text = gEasyChatWord_Couldnt,
        .alphabeticalOrder = 11,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAPABLE)] =
    {
        .text = gEasyChatWord_Capable,
        .alphabeticalOrder = 9,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DISAPPEAR)] =
    {
        .text = gEasyChatWord_Disappear,
        .alphabeticalOrder = 29,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_APPEAR)] =
    {
        .text = gEasyChatWord_Appear,
        .alphabeticalOrder = 69,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THROW)] =
    {
        .text = gEasyChatWord_Throw,
        .alphabeticalOrder = 68,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WORRY)] =
    {
        .text = gEasyChatWord_Worry,
        .alphabeticalOrder = 66,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SLEPT)] =
    {
        .text = gEasyChatWord_Slept,
        .alphabeticalOrder = 61,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SLEEP)] =
    {
        .text = gEasyChatWord_Sleep,
        .alphabeticalOrder = 52,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RELEASE)] =
    {
        .text = gEasyChatWord_Release,
        .alphabeticalOrder = 51,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DRINKS)] =
    {
        .text = gEasyChatWord_Drinks,
        .alphabeticalOrder = 40,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RUNS)] =
    {
        .text = gEasyChatWord_Runs,
        .alphabeticalOrder = 62,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RUN)] =
    {
        .text = gEasyChatWord_Run,
        .alphabeticalOrder = 35,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WORKS)] =
    {
        .text = gEasyChatWord_Works,
        .alphabeticalOrder = 20,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WORKING)] =
    {
        .text = gEasyChatWord_Working,
        .alphabeticalOrder = 71,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TALKING)] =
    {
        .text = gEasyChatWord_Talking,
        .alphabeticalOrder = 60,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TALK)] =
    {
        .text = gEasyChatWord_Talk,
        .alphabeticalOrder = 59,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SINK)] =
    {
        .text = gEasyChatWord_Sink,
        .alphabeticalOrder = 15,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMACK)] =
    {
        .text = gEasyChatWord_Smack,
        .alphabeticalOrder = 16,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PRETEND)] =
    {
        .text = gEasyChatWord_Pretend,
        .alphabeticalOrder = 38,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PRAISE)] =
    {
        .text = gEasyChatWord_Praise,
        .alphabeticalOrder = 49,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OVERDO)] =
    {
        .text = gEasyChatWord_Overdo,
        .alphabeticalOrder = 25,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHOW)] =
    {
        .text = gEasyChatWord_Show,
        .alphabeticalOrder = 21,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOOKS)] =
    {
        .text = gEasyChatWord_Looks,
        .alphabeticalOrder = 42,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEES)] =
    {
        .text = gEasyChatWord_Sees,
        .alphabeticalOrder = 43,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEEK)] =
    {
        .text = gEasyChatWord_Seek,
        .alphabeticalOrder = 44,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OWN)] =
    {
        .text = gEasyChatWord_Own,
        .alphabeticalOrder = 12,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TAKE)] =
    {
        .text = gEasyChatWord_Take,
        .alphabeticalOrder = 13,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALLOW)] =
    {
        .text = gEasyChatWord_Allow,
        .alphabeticalOrder = 7,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FORGET)] =
    {
        .text = gEasyChatWord_Forget,
        .alphabeticalOrder = 8,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FORGETS)] =
    {
        .text = gEasyChatWord_Forgets,
        .alphabeticalOrder = 10,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_APPEARS)] =
    {
        .text = gEasyChatWord_Appears,
        .alphabeticalOrder = 58,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FAINT)] =
    {
        .text = gEasyChatWord_Faint,
        .alphabeticalOrder = 57,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FAINTED)] =
    {
        .text = gEasyChatWord_Fainted,
        .alphabeticalOrder = 50,
        .enabled = TRUE,
    },
};
