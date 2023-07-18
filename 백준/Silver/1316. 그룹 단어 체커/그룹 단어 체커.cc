#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int N;
	cin >> N;
	char alphabet[100];
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> alphabet;
			if (strlen(alphabet) <= 2)//단어 수가 2개 이하면 그룹단어고 봐도 무방
			{
				count++;
			}
			else
			{
				int count02 = 0;

				for (int j = 2; j < strlen(alphabet); j++)//입력한 길이만큼 반복 단 알파벨을 비교해야 하므로 3번째부터 비교할 수 있게 j를 2부터 시작함.
				{
					for (int k = 0; k < j - 1; k++)//k를 j보다 1만큼 적게 반복
					{
						if (alphabet[k] == alphabet[j] && alphabet[k+1] == alphabet[j])
						{
							continue; //k와 j의 값이 같고 k+1과 j의 값이 같으면 그룹단어임
						}
						else if (alphabet[k] == alphabet[j])
						{
							count02++;//k와 j의 값이 같으면 그룹단어 제외 카운트에 추가
						}
					}
				}
				if (count02 == 0)
				{
					count++;
				}
			}
	}
	cout << count;
	return 0;
}