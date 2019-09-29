	void exkmp() {
		int core = 1;
		int bound;
		for (int i = 1; i <= n; i++) {
			if (s[i] != s[i - 1] || i == n) {
				nxt[1] = i - 1;
				bound = i - 1;
				break;
			}
		}
		for (int i = 2; i < n; i++) {
			if (i + nxt[i - core] - 1 < bound) {
				nxt[i] = nxt[i - core];
			} else {
				int now = max(0, bound - i + 1);
				while (s[now] == s[i + now]) {
					++now;
				}
				nxt[i] = now;
				core = i;
				bound = i + nxt[i] - 1;
			}
		}
	}
