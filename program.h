#ifndef PROGRAM_H
#define PROGRAM_H
#define FOREACH_OPTION(Option) \
    Option(Add)                \
        Option(Modify)         \
            Option(List)       \
                Option(Delete) \ 
                    Option(Exit)

#define GENERATE_ENUM(ENUM) ENUM,
#define GENERATE_STRING(STRING) #STRING,

typedef enum Options
{
    FOREACH_OPTION(GENERATE_ENUM)
} Options;

static const char *OPTIONS_STRING[] = {
    FOREACH_OPTION(GENERATE_STRING)};

const static OPTIONS_SIZE = sizeof(OPTIONS_STRING) / sizeof(OPTIONS_STRING[0]);

static inline void PrintOptions()
{
    for (int i = 1; i <= OPTIONS_SIZE; i++)
        printf("(%d)-%s\n", i, OPTIONS_STRING[i - 1]);
}
static inline int GetSelection(void)
{
    int tmp = 0;
    PrintOptions();
    printf("Selection: ");
    scanf("%d", &tmp);

    if (tmp < 1 || tmp > OPTIONS_SIZE)
        return -1;

    return tmp - 1;
}
#endif