# -*- coding: utf-8 -*-
# ---
# jupyter:
#   jupytext:
#     text_representation:
#       extension: .py
#       format_name: light
#       format_version: '1.4'
#       jupytext_version: 1.1.5
#   kernelspec:
#     display_name: Octave
#     language: octave
#     name: octave
# ---

a = [1 2 3; 1 1 1]
b = [1 1; 2 2]
c = [1 1; 2 1; 3 1]

eig(b)

[v, lambda] = eig(b)

rank(a)
rank(b)
rank(c)

[u, s, v] = svd(a)

[u, s, v] = svd(b)

[u, s, v] = svd(c)

pinv(a)
pinv(b)
pinv(c)

% 一般の求め方
aa = [3;2]
bb = [2;3]
cc = [1;2;1]
a\aa
b\bb
c\cc

% 一般化逆行列による求め方
pinv(a)*aa
pinv(b)*bb
pinv(c)*cc


