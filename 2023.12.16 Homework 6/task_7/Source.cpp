#include<iostream>

int n[4]{ 0 };
int** d = new int* [4]{ nullptr, new int[10], new int[10], new int[10] };
int operations = 0;

void last_cone()
{
    std::cout << "last cone" << std::endl;
    for (int j = n[3] - 1; j >= 0; j--)
    {
        std::cout << d[3][j] << " ";
    }
    std::cout << std::endl;
    std::cout << "top----->----down" << std::endl;
    std::cout << std::endl << std::endl;
}

void mid_cone()
{
    std::cout << "mid cone" << std::endl;
    for (int j = n[2] - 1; j >= 0; j--)
    {
        std::cout << d[2][j] << " ";
    }
    std::cout << std::endl;
}

void first_cone()
{
    std::cout << "top----->----down" << std::endl;
    std::cout << "first cone" << std::endl;
    for (int j = n[1] - 1; j >= 0; j--)
    {
        std::cout << d[1][j] << " ";
    }
    std::cout << std::endl;
}

void shift(int from = 1, int to = 2)
{
    std::cout << d[from][n[from] - 1] << " " << from << " " << to << std::endl;
    d[to][n[to]++] = d[from][--n[from]];
    // Uncomment for debug
    // first_cone();
    // mid_cone();
    // last_cone();
    operations++;
}

void hanoy(int count, int from = 1, int to = 2)
{
    if (count == 0)
    {
        return;
    }

    int res = 6 - from - to;

    hanoy(count - 1, from, res);
    shift(from, to);
    hanoy(count - 1, res, to);

}

void sort()
{
    shift(1, 2);

    while (n[1] > 0 && operations < 200000)
    {
        int temp_count = 0;
        for (int i = n[2] - 1; i >= 0; i--)
        {
            if (d[2][i] < d[1][n[1] - 1])
            {
                temp_count = n[2] - i;
            }
        }

        hanoy(temp_count, 2, 3);
        shift(1, 2);
        hanoy(temp_count, 3, 2);
    }
}


int main(int argc, char* argv[])
{
    std::cin >> n[1];
    for (int i = n[1] - 1; i >= 0; --i)
    {
        std::cin >> d[1][i];
    }
    if (n[1] > 1)
    {
        sort();
    }

    // Uncomment for check result
    // std::cout << "RESULT" << std::endl;
    //first_cone();
    //mid_cone();
    //last_cone();

    return EXIT_SUCCESS;
}