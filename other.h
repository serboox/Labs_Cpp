
//Прототипы используемых в данном задании функций:

std::string format(const char *fmt, ...);

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
public:
    void print() {
        std::printf("Books{\n"
                 "\tauthorFirstName:%s\n"
                 "\tauthorLastName: %s\n"
                 "\tbookTitle: %s\n"
                 "\tbookYear: %d\n"
                 "\tbookPrice: %f\n"
                 "\tbookCategory: %s\n}\n",
                 authorFirstName.c_str(),
                 authorLastName.c_str(),
                 bookTitle.c_str(),
                 bookYear,
                 bookPrice,
                 bookCategory.c_str());
    };
};

