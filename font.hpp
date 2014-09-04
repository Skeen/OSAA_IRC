#ifndef FONT_HPP
#define FONT_HPP

//TODO: Move all of this into a namespace, to avoid pulluting global namespace
//      Make the changes to irc.cpp

// This is always static
constexpr uint8_t LETTER_HEIGHT = 6;

// The maximum sizes of letters
//-----------------------------
// This one can be changed, to support wide letteres
constexpr uint8_t MAX_LETTER_WIDTH  = 6;
// This one is locked! Cannot be changed, without patching irc.cpp
constexpr uint8_t MAX_LETTER_HEIGHT = LETTER_HEIGHT;

// The struct used to define letters
typedef struct
{
    // The width of this pix_map letter
    uint8_t letter_width;
    // A pointer to the pix_map array
    uint8_t pix_map[MAX_LETTER_HEIGHT*MAX_LETTER_WIDTH];
} Letter;

//---------------//
// Letters below //
//---------------//
Letter a = {
    .letter_width = 5,
    .pix_map = {
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 0,
    0, 0, 0, 1, 1,
    0, 1, 1, 1, 1,
    1, 0, 0, 1, 1,
    0, 1, 1, 1, 1,
    },
};

Letter b = {
    .letter_width = 5,
    .pix_map = {
    1, 1, 0, 0, 0,
    1, 1, 0, 0, 0,
    1, 1, 1, 1, 0,
    1, 1, 0, 0, 1,
    1, 1, 0, 0, 1,
    1, 1, 1, 1, 0,
    },
};

Letter c = {
    .letter_width = 5,
    .pix_map = {
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 1,
    1, 1, 0, 0, 0,
    1, 1, 0, 0, 0,
    1, 1, 0, 0, 0,
    0, 1, 1, 1, 1,
    },
};

Letter d = {
    .letter_width = 5,
    .pix_map = {
    0, 0, 0, 1, 1,
    0, 0, 0, 1, 1,
    0, 1, 1, 1, 1,
    1, 0, 0, 1, 1,
    1, 0, 0, 1, 1,
    0, 1, 1, 1, 1,
    },
};

Letter e = {
    .letter_width = 5,
    .pix_map = {
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 0,
    1, 0, 0, 1, 1,
    1, 1, 1, 1, 1,
    1, 0, 0, 0, 0,
    0, 1, 1, 1, 0,
    },
};

Letter f = {
    .letter_width = 4,
    .pix_map = {
    0, 0, 1, 1,
    0, 1, 1, 0,
    1, 1, 1, 1,
    0, 1, 1, 0,
    0, 1, 1, 0,
    0, 1, 1, 0,
    },
};

Letter g = {
    .letter_width = 5,
    .pix_map = {
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 1,
    1, 0, 0, 1, 1,
    0, 1, 1, 1, 1,
    0, 0, 0, 1, 1,
    0, 1, 1, 1, 1,
    },
};

Letter h = {
    .letter_width = 5,
    .pix_map = {
    1, 1, 0, 0, 0,
    1, 1, 0, 0, 0,
    1, 1, 1, 1, 0,
    1, 1, 0, 0, 1,
    1, 1, 0, 0, 1,
    1, 1, 0, 0, 1,
    },
};

Letter i = {
    .letter_width = 2,
    .pix_map = {
    1, 1,
    0, 0,
    1, 1,
    1, 1,
    1, 1,
    1, 1,
    },
};

Letter j = {
    .letter_width = 3,
    .pix_map = {
    0, 1, 1,
    0, 0, 0,
    0, 1, 1,
    0, 1, 1,
    0, 1, 1,
    1, 1, 1,
    },
};

Letter k = {
    .letter_width = 4,
    .pix_map = {
    1, 1, 0, 0,
    1, 1, 0, 1,
    1, 1, 1, 0,
    1, 1, 0, 0,
    1, 1, 1, 0,
    1, 1, 0, 1,
    },
};

Letter l = {
    .letter_width = 2,
    .pix_map = {
    1, 1,
    1, 1,
    1, 1,
    1, 1,
    1, 1,
    1, 1,
    },
};

Letter m = {
    .letter_width = 6,
    .pix_map = {
    0, 0, 0, 0, 0, 0,
    1, 1, 1, 0, 1, 0,
    1, 1, 1, 1, 1, 1,
    1, 1, 0, 1, 0, 1,
    1, 1, 0, 1, 0, 1,
    1, 1, 0, 1, 0, 1,
    },
};

Letter n = {
    .letter_width = 5,
    .pix_map = {
    0, 0, 0, 0, 0,
    1, 1, 1, 1, 0,
    1, 1, 0, 0, 1,
    1, 1, 0, 0, 1,
    1, 1, 0, 0, 1,
    1, 1, 0, 0, 1,
    },
};

Letter o = {
    .letter_width = 5,
    .pix_map = {
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 0,
    1, 1, 0, 0, 1,
    1, 1, 0, 0, 1,
    1, 1, 0, 0, 1,
    0, 1, 1, 1, 0,
    },
};

Letter p = {
    .letter_width = 5,
    .pix_map = {
    0, 0, 0, 0, 0,
    1, 1, 1, 1, 0,
    1, 1, 0, 0, 1,
    1, 1, 0, 0, 1,
    1, 1, 1, 1, 0,
    1, 1, 0, 0, 0,
    },
};

Letter q = {
    .letter_width = 5,
    .pix_map = {
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 1,
    1, 0, 0, 1, 1,
    1, 0, 0, 1, 1,
    0, 1, 1, 1, 1,
    0, 0, 0, 1, 1,
    },
};

Letter r = {
    .letter_width = 4,
    .pix_map = {
    0, 0, 0, 0,
    1, 0, 1, 1,
    1, 1, 0, 0,
    1, 1, 0, 0,
    1, 1, 0, 0,
    1, 1, 0, 0,
    },
};

Letter s = {
    .letter_width = 5,
    .pix_map = {
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 1,
    1, 1, 0, 0, 0,
    0, 1, 1, 1, 0,
    0, 0, 0, 1, 1,
    1, 1, 1, 1, 0,
    },
};

Letter t = {
    .letter_width = 4,
    .pix_map = {
    0, 1, 1, 0,
    0, 1, 1, 0,
    1, 1, 1, 1,
    0, 1, 1, 0,
    0, 1, 1, 0,
    0, 0, 1, 0,
    },
};

Letter u = {
    .letter_width = 5,
    .pix_map = {
    0, 0, 0, 0, 0,
    1, 1, 0, 0, 1,
    1, 1, 0, 0, 1,
    1, 1, 0, 0, 1,
    1, 1, 0, 0, 1,
    0, 1, 1, 1, 0,
    },
};

Letter v = {
    .letter_width = 5,
    .pix_map = {
    0, 0, 0, 0, 0,
    1, 1, 0, 0, 1,
    1, 1, 0, 0, 1,
    1, 1, 0, 0, 1,
    0, 1, 0, 1, 0,
    0, 0, 1, 0, 0,
    },
};

Letter w = {
    .letter_width = 5,
    .pix_map = {
    0, 0, 0, 0, 0,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 1, 0, 1,
    1, 0, 1, 0, 1,
    0, 1, 0, 1, 0,
    },
};

Letter x = {
    .letter_width = 5,
    .pix_map = {
    0, 0, 0, 0, 0,
    1, 0, 0, 0, 1,
    0, 1, 0, 1, 0,
    0, 1, 1, 1, 0,
    0, 1, 0, 1, 0,
    1, 0, 0, 0, 1,
    },
};

Letter y = {
    .letter_width = 4,
    .pix_map = {
    0, 0, 0, 0,
    1, 0, 0, 1,
    1, 0, 0, 1,
    0, 1, 1, 1,
    0, 0, 0, 1,
    1, 1, 1, 0,
    },
};

Letter z = {
    .letter_width = 4,
    .pix_map = {
    0, 0, 0, 0,
    1, 1, 1, 1,
    0, 0, 1, 1,
    0, 1, 1, 0,
    1, 1, 0, 0,
    1, 1, 1, 1,
    },
};

//---------------//
// Letters above //
//----------------//
// Specials below //
//----------------//
Letter empty = {
    .letter_width = 1,
    .pix_map = {
    0,
    0,  
    0,
    0,
    0,
    0,
    },
};

Letter dash = {
    .letter_width = 3,
    .pix_map = {
    0, 0, 0,
    0, 0, 0,
    1, 1, 1,
    1, 1, 1,
    0, 0, 0,
    0, 0, 0,
    },
};

Letter underscore = {
    .letter_width = 4,
    .pix_map = {
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    1, 1, 1, 1,
    1, 1, 1, 1,
    },
};

Letter quotes = {
    .letter_width = 3,
    .pix_map = {
    1, 0, 1,
    1, 0, 1,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0, 
    },
};

Letter bang = {
    .letter_width = 1,
    .pix_map = {
    1,
    1, 
    1,
    1,
    0,
    1,
    },
};

Letter question_mark = {
    .letter_width = 3,
    .pix_map = {
    0, 1, 0,
    1, 0, 1,
    0, 0, 1,
    0, 1, 0,
    0, 0, 0,
    0, 1, 0,
    },
};

Letter space = {
    .letter_width = 2,
    .pix_map = {
    0, 0,
    0, 0,  
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    },
};

Letter comma = {
    .letter_width = 1,
    .pix_map = {
    0,
    0,
    0,
    0,
    1, 
    1, 
    },
};

Letter dot = {
    .letter_width = 1,
    .pix_map = {
    0, 
    0,
    0,
    0,
    0,
    1,
    },
};

Letter colon = {
    .letter_width = 1,
    .pix_map = {
    0, 
    0,
    1,
    0,
    1,
    0,
    },
};

Letter semi_colon = {
    .letter_width = 1,
    .pix_map = {
    0, 
    0,
    1,
    0,
    1,
    1,
    },
};

Letter undef = {
    .letter_width = 5,
    .pix_map = {
    0, 0, 1, 0, 0,
    0, 1, 1, 1, 0,
    0, 1, 1, 1, 0,
    1, 1, 1, 1, 1,
    0, 0, 1, 0, 0,
    0, 1, 0, 1, 0,
    },
};

Letter hash = {
    .letter_width = 5,
    .pix_map = {
    0, 0, 0, 0, 0,
    0, 0, 1, 0, 1,
    1, 1, 1, 1, 1,
    0, 1, 0, 1, 0,
    1, 1, 1, 1, 1,
    1, 0, 1, 0, 0,
    },
};

Letter dollar = {
    .letter_width = 5,
    .pix_map = {
    0, 1, 1, 1, 0,
    1, 0, 1, 0, 1,
    1, 1, 1, 0, 0,
    0, 0, 1, 1, 1,
    1, 0, 1, 0, 1,
    0, 1, 1, 1, 0,
    },
};

Letter precentage = {
    .letter_width = 5,
    .pix_map = {
    1, 1, 0, 0, 1,
    1, 1, 0, 1, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 1, 0, 1, 1,
    1, 0, 0, 1, 1,
    },
};

Letter and_sign = {
    .letter_width = 5,
    .pix_map = {
    0, 1, 1, 0, 0,
    1, 0, 0, 1, 0,
    0, 1, 1, 0, 0,
    0, 1, 1, 1, 1,
    1, 0, 0, 1, 0,
    0, 1, 1, 1, 1,
    },
};

Letter single_quote = {
    .letter_width = 1,
    .pix_map = {
    0,
    1,
    1,
    0,
    0,
    0,
    },
};

Letter lparen = {
    .letter_width = 2,
    .pix_map = {
    0, 1,
    1, 0,
    1, 0,
    1, 0,
    1, 0,
    0, 1,
    },
};

Letter rparen = {
    .letter_width = 2,
    .pix_map = {
    1, 0,
    0, 1,
    0, 1,
    0, 1,
    0, 1,
    1, 0,
    },
};

Letter star = {
    .letter_width = 5,
    .pix_map = {
    0, 0, 1, 0, 0,
    1, 0, 1, 0, 1,
    0, 1, 1, 1, 0,
    1, 0, 1, 0, 1,
    0, 0, 1, 0, 0,
    0, 0, 0, 0, 0,
    },
};

Letter plus = {
    .letter_width = 3,
    .pix_map = {
    0, 0, 0,
    0, 0, 0,
    0, 1, 0,
    1, 1, 1,
    0, 1, 0,
    0, 0, 0,
    },
};

Letter slash = {
    .letter_width = 3,
    .pix_map = {
    0, 0, 1,
    0, 0, 1,
    0, 1, 0,
    0, 1, 0,
    1, 0, 0,
    1, 0, 0,
    },
};

Letter back_slash = {
    .letter_width = 3,
    .pix_map = {
    1, 0, 0,
    1, 0, 0,
    0, 1, 0,
    0, 1, 0,
    0, 0, 1,
    0, 0, 1,
    },
};

Letter zero = {
    .letter_width = 4,
    .pix_map = {
    0, 1, 1, 0,
    1, 1, 0, 1,
    1, 0, 0, 1,
    1, 0, 0, 1,
    1, 0, 0, 1,
    0, 1, 1, 0,
    },
};

Letter one = {
    .letter_width = 4,
    .pix_map = {
    0, 1, 1, 0,
    1, 1, 1, 0,
    0, 1, 1, 0,
    0, 1, 1, 0,
    0, 1, 1, 0,
    1, 1, 1, 1,
    },
};

Letter two = {
    .letter_width = 5,
    .pix_map = {
    0, 1, 1, 1, 0,
    1, 1, 0, 0, 1,
    0, 0, 0, 0, 1,
    0, 1, 1, 1, 0,
    1, 1, 0, 0, 0,
    1, 1, 1, 1, 1,
    },
};

Letter three = {
    .letter_width = 5,
    .pix_map = {
    0, 1, 1, 1, 0,
    1, 1, 0, 0, 1,
    0, 0, 0, 1, 0,
    0, 0, 0, 1, 1,
    1, 1, 0, 0, 1,
    0, 1, 1, 1, 0,
    },
};

Letter four = {
    .letter_width = 5,
    .pix_map = {
    0, 0, 0, 1, 0,
    0, 0, 1, 1, 0,
    0, 1, 0, 1, 0,
    1, 1, 1, 1, 1,
    0, 0, 0, 1, 0,
    0, 0, 0, 1, 0,
    },
};

Letter five = {
    .letter_width = 5,
    .pix_map = {
    1, 1, 1, 1, 1,
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    1, 1, 1, 1, 0,
    0, 0, 0, 0, 1,
    1, 1, 1, 1, 0,
    },
};

Letter six = {
    .letter_width = 5,
    .pix_map = {
    0, 1, 1, 1, 1,
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    1, 1, 1, 1, 0,
    1, 0, 0, 0, 1,
    0, 1, 1, 1, 0,
    },
};

Letter seven = {
    .letter_width = 5,
    .pix_map = {
    1, 1, 1, 1, 1,
    0, 0, 0, 0, 1,
    0, 0, 0, 1, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    },
};

Letter eight = {
    .letter_width = 5,
    .pix_map = {
    0, 1, 1, 1, 0,
    1, 0, 0, 0, 1,
    0, 1, 1, 1, 0,
    0, 1, 1, 1, 0,
    1, 0, 0, 0, 1,
    0, 1, 1, 1, 0,
    },
};

Letter nine = {
    .letter_width = 5,
    .pix_map = {
    0, 1, 1, 1, 0,
    1, 0, 0, 0, 1,
    0, 1, 1, 1, 1,
    0, 0, 0, 0, 1,
    0, 0, 0, 0, 1,
    0, 1, 1, 1, 0,
    },
};

Letter ltub = {
    .letter_width = 3,
    .pix_map = {
    0, 0, 1,
    0, 1, 0,
    1, 1, 0,
    1, 1, 0,
    0, 1, 0,
    0, 0, 1,
    },
};

Letter line = {
    .letter_width = 1,
    .pix_map = {
    1, 
    1, 
    1,
    1,
    1, 
    1, 
    },
};

Letter lt = {
    .letter_width = 5,
    .pix_map = {
    0, 0, 0,
    0, 0, 1,
    0, 1, 0,
    1, 0, 0,
    0, 1, 0,
    0, 0, 1,
    },
};

Letter gt = {
    .letter_width = 5,
    .pix_map = {
    0, 0, 0,
    1, 0, 0,
    0, 1, 0,
    0, 0, 1,
    0, 1, 0,
    1, 0, 0,
    },
};

Letter eq = {
    .letter_width = 5,
    .pix_map = {
    0, 0, 0,
    0, 0, 0,
    1, 1, 1,
    0, 0, 0,
    1, 1, 1,
    0, 0, 0,
    },
};


Letter at = {
    .letter_width = 5,
    .pix_map = {
    0, 1, 1, 1, 0,
    1, 0, 0, 1, 0,
    1, 0, 1, 1, 0,
    1, 0, 1, 1, 0,
    1, 0, 0, 0, 0,
    0, 1, 1, 1, 1,
    },
};

Letter rbracket = {
    .letter_width = 2,
    .pix_map = {
    1, 1,
    0, 1,
    0, 1,
    0, 1,
    0, 1,
    1, 1,
    },
};

Letter lbracket = {
    .letter_width = 2,
    .pix_map = {
    1, 1,
    1, 0,
    1, 0,
    1, 0,
    1, 0,
    1, 1,
    },
};

Letter hat = {
    .letter_width = 3,
    .pix_map = {
    0, 1, 0,
    1, 1, 1,
    1, 0, 1,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
    },
};

Letter grave = {
    .letter_width = 2,
    .pix_map = {
    1, 1, 
    0, 1, 
    0, 0,
    0, 0,
    0, 0,
    0, 0,
    },
};

Letter rtub = {
    .letter_width = 3,
    .pix_map = {
    1, 0, 0,
    0, 1, 0,
    0, 1, 1,
    0, 1, 1,
    0, 1, 0,
    1, 0, 0,
    },
};

Letter tilde = {
    .letter_width = 4,
    .pix_map = {
    0, 0, 0, 0,
    0, 1, 0, 1,
    1, 1, 1, 1,
    1, 0, 1, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    },
};



//----------------//
// Specials above //
//----------------//

Letter ASCII[] = {
    // '\0', 
    undef, 
    // 'start of heading'
    undef,
    // 'start of text'
    undef,
    // 'end of text'
    undef,
    // 'end of transmission'
    undef,
    // 'enquiry'
    undef,
    // 'acknowledge'
    undef,
    // 'bell'
    undef,
    // 'backspace'
    undef,
    // 'horizontal tab'
    empty,
    // 'NL line feed, new line'
    empty,
    // 'vertical tab'
    undef,
    // 'NP form feed, new page'
    empty,
    // 'carraige return'
    empty,
    // 'shift out'
    undef,
    // 'shift in'
    undef,
    // 'data link escape'
    undef,
    // 'device control 1'
    undef,
    // 'device control 2'
    undef,
    // 'device control 3'
    undef,
    // 'device control 4'
    undef,
    // 'negative acknowledge'
    undef,
    // 'synchronous idle'
    undef,
    // 'end of trans, block'
    undef,
    // 'cancel'
    undef,
    // 'end of medium'
    undef,
    // 'substitute'
    undef,
    // 'escape'
    undef,
    // 'file separator'
    undef,
    // 'group seperator'
    undef,
    // 'record seperator'
    undef,
    // 'unit seperator'
    undef,
    //----------------//
    // SPECIALS BELOW //
    //----------------//
    space,
    bang,
    quotes,
    hash,
    dollar,
    precentage,
    and_sign,
    single_quote,
    lparen,
    rparen,
    star,
    plus,
    comma,
    dash,
    dot,
    slash,
    //---------------//
    // NUMBERS BELOW //
    //---------------//
    zero,
    one,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    //----------------//
    // SPECIALS BELOW //
    //----------------//
    colon,
    semi_colon,
    gt,
    eq,
    lt,
    question_mark,
    at,
    //-----------------------//
    // CAPITAL LETTERS BELOW //
    //-----------------------//
    // TODO: Capital letters
    a, b, c, d, e, f, g,
    h, i, j, k, l, m, n,
    o, p, q, r, s, t, u,
    v, w, x, y, z,
    //----------------//
    // SPECIALS BELOW //
    //----------------//
    lbracket,
    back_slash,
    rbracket,
    hat,
    underscore,
    grave,
    //---------------//
    // LETTERS BELOW //
    //---------------//
    a, b, c, d, e, f, g,
    h, i, j, k, l, m, n,
    o, p, q, r, s, t, u,
    v, w, x, y, z,
    //----------------//
    // SPECIALS BELOW //
    //----------------//
    ltub,
    line,
    rtub,
    tilde,
    // 'DEL'
    undef,
};

#endif //FONT_HPP
