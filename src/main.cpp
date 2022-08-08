#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

const auto& vx = vi{ 1, -1, 0, 0 };
const auto& vy = vi{ 0, 0, -1, 1 };

int cross(int a, int b) {
	const auto& x1 = vx[a - 1];
	const auto& y1 = vy[a - 1];

	const auto& x2 = vx[b - 1];
	const auto& y2 = vy[b - 1];

	return x1 * y2 - y1 * x2;
};

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	auto k = int{};
	cin >> k;

	auto horz = int{ -1 };
	auto vert = int{ -1 };
	auto s1 = int{ -1 };
	auto s2 = int{ -1 };
	auto bfDir = int{ -1 };
	auto bfLen = int{ -1 };
	for (auto i = 0; i < 6; ++i) {
		auto dir = int{};
		auto len = int{};
		cin >> dir >> len;

		if (1 == dir || 2 == dir) {
			if (vert < len) {
				vert = len;
			}

			if (0 == i) {
				s1 = len;
			}
		}
		else if (3 == dir || 4 == dir) {
			if (horz < len) {
				horz = len;
			}

			if (0 == i) {
				s1 = len;
			}
		}

		if (0 < i) {
			if (cross(bfDir, dir) < 0) {
				s1 = bfLen;
				s2 = len;
			}
		}

		if (5 == i && s2 < 0) {
			s2 = len;
		}

		bfDir = dir;
		bfLen = len;
	}

	cout << k * (horz * vert - s1 * s2);

	return 0;
}