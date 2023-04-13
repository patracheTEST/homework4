typedef struct
{
    int row; // 행렬의 열 크기 이중배열의 두번째 인덱스에 쓰일 예정
    int column; // 행렬의 행 크기 이중배열의 첫번째 인덱스에 쓰일 예정
    int **matrixValue; // 행렬의 값들을 저장할 이차원 포인터
} matrix;