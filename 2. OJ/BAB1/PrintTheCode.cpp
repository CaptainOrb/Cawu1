#include <stdio.h>

int main()
{
    char input[101];
    scanf("%[^\n]s", input);

    printf("#include <stdio.h>\n");
    printf("int main()\n");
    printf("{\n");
    printf("    printf(\"%s\\n\",\"%s\");\n", "%s", input);
    printf("    return 0;\n");
    printf("}\n");
}