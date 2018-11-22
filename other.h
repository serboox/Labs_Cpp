
//Прототипы используемых в данном задании функций:

void Sort(char *pcFirst, int nNumber, int size,
          void (*Swap)(void *, void *), int (*Compare)(void *, void *));

void SwapInt(void *p1, void *p2);

int CmpInt(void *p1, void *p2);

struct BOOK {
    std::string authorFirstName; // 24
    std::string authorLastName; // 24

    std::string bookTitle; // 24
    short int bookYear; // 2
    /* 2 padding byte */
    float bookPrice; // 4
    std::string bookCategory; // 24
};

