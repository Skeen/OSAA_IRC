#ifndef FONT_HPP
#define FONT_HPP

constexpr uint8_t MAX_LETTER_WIDTH  = 6;
constexpr uint8_t MAX_LETTER_HEIGHT = 6;
// This is always static
constexpr uint8_t LETTER_HEIGHT = 6;

typedef struct
{
    // The width of this pix_map letter
    uint8_t letter_width;
    // A pointer to the pix_map array
    uint8_t pix_map[MAX_LETTER_HEIGHT*MAX_LETTER_WIDTH];
} Letter;

// Letters below
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
