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

//----------------//
// Specials above //
//-------------------//
// Collections below //
//-------------------//

Letter Alphabet_Small[] = {
    a, b, c, d, e, f,
    g, h, i, j, k, l,
    m, n, o, p, q, r,
    s, t, u, v, w, x,
    y, z, 
};

// TODO: Add large letters
#define Alphabet_Large Alphabet_Small

#endif //FONT_HPP
