	char s[MXN], org[MXN];
	int len[MXN];
	int n, on = strlen(org)
	s[0] = -1;
	for (int i = 1; i <= on; i++) {
		s[++n] = '#';
		s[++n] = org[i - 1];
	}
	s[++n] = '#';
	int r = 1, c = 1;
	for (int i = 2; i <= n; i++) {
		len[i] = len[c - (i - c)];
		if (i + len[i] < r) {
		} else {
			len[i] = r - i;
			while (s[i + len[i] + 1] == s[i - len[i] - 1]) {
				++len[i];
			}
			c = i;
			r = i + len[i];
		}
	}

