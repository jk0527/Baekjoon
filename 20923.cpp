#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef vector<deque<int>> cards;
const int DO = 0, SU = 1;

// 승리 판단하기
string judge(cards& deck)
{
	int do_deck = deck[DO].size(), su_deck = deck[SU].size();
	if (do_deck > su_deck) {
		return "do";
	}
	else if (do_deck < su_deck) {
		return "su";
	}
	return "dosu";
}

// 그라운드에서 덱으로 카드 옮기기
void groundToDeck(deque<int>& deck, deque<int>& ground) {
	while (!ground.empty()) {
		deck.push_back(ground.back());
		ground.pop_back();
	}
}

// 종을 울릴 수 있는 사람 판단
int whoCanRingTheBell(cards& deck, cards& ground) {
	if (!ground[DO].empty() && ground[DO].front() == 5) {
		return DO;
	}
	else if (!ground[SU].empty() && ground[SU].front() == 5) {
		return DO;
	}
	else if (!ground[DO].empty() && !ground[SU].empty() && (ground[DO].front() + ground[SU].front() == 5)) {
		return SU;
	}
	return -1;
}

void ringTheBell(int player, cards& deck, cards& ground) {
	groundToDeck(deck[player], ground[!player]); // 카드 가져가기 (상대 그라운드 -> 본인 덱)
	groundToDeck(deck[player], ground[player]); // 카드 가져가기 (본인 그라운드 -> 본인 덱)
}

// 게임 진행
string game(int m, cards& deck, cards& ground) {
	bool turn = DO; // 도도 먼저
	while (m--)
	{
		ground[turn].push_front(deck[turn].front()); // 카드 내려놓기(덱 -> 그라운드)
		deck[turn].pop_front();
		if (deck[turn].empty()) {
			break;
		}
		int bell = whoCanRingTheBell(deck, ground); // 벨을 울릴 수 있는 사람
		if (bell != -1) { // 종을 친 경우
			ringTheBell(bell, deck, ground);
		}
		turn = !turn; // 차례 바꾸기
	}
	return judge(deck);
}

int main()
{
	int n, m, card1, card2;
	cards deck(2), ground(2); // 0: 도도, 1: 수연
	// 입력
	cin >> n >> m;
	while (n--) {
		cin >> card1 >> card2;
		deck[0].push_front(card1);
		deck[1].push_front(card2);
	}
	// 출력 & 연산
	cout << game(m, deck, ground) << '\n';
	return 0;
}
