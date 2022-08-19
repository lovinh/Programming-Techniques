// Thực hiện cấu trúc một thư viện xử lý và cấp phát chuỗi custom_string. Thư viện này bao gồm một số hàm như sau:
// 1. Hàm cấp phát và đọc một chuỗi.
// 2. Hàm sao chép chuỗi.
// 3. Hàm trả về độ dài chuỗi
// 4. Hàm nối chuỗi.
// 5. Hàm tìm kiếm vị trí xuất hiện đầu tiên của một ký tự đã cho trong chuỗi

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Khởi tạo và đọc chuỗi
char *createString(FILE *stream, int maxChar);

// Sao chép chuỗi nguồn sang đích
void stringCopy(char **destination, const char *source);

// Lấy độ dài chuỗi
unsigned int stringLength(const char *str);

// Mở rộng chuỗi đích với chuỗi nguồn
void stringConcat(char *destination, const char *source);

// Tìm kiếm ký tự c trong chuỗi
unsigned int stringCFind(char c, const char *str);
int main(int argc, char const *argv[])
{
    char *s = createString(stdin, 256);
    printf("Chuoi s = %s\n", s);
    char *des = NULL;
    stringCopy(&des, s);
    printf("Chuoi sau copy: %s\n", des);
    s[0] = 'V';
    printf("Chuoi s = %s\n", s);
    printf("Chuoi sau copy: %s", des);

    return 0;
}

char *createString(FILE *stream, int maxChar)
{
    char *s = NULL;
    // Cấp phát bộ nhớ để lưu trữ chuỗi
    s = (char *)malloc(maxChar * sizeof(char));

    // Đọc chuỗi này từ đầu vào
    fscanf(stream, "%[^\n]s", s);

    // Tái cấp phát vùng nhớ
    s = realloc(s, strlen(s) + 1);

    return s;
}

void stringCopy(char **destination, const char *source)
{
    // destination = source; // Sai do  hai con trỏ sẽ trỏ tới cùng một chuỗi

    // Cấp phát vùng bộ nhớ mới vừa đủ để chứa nội dung chuỗi source
    char *tmp = (char *)malloc((strlen(source) + 1) * sizeof(char));

    // Copy dữ liệu từ source sang vùng nhớ mới.
    for (int i = 0; i < strlen(source); i++)
    {
        tmp[i] = source[i];
    }
    tmp[strlen(source)] = '\0';

    // Giải phóng vùng nhớ trỏ bởi destination nếu có
    free(*destination);

    *destination = tmp;
}
