# ex.3.4

## task

en: Do Exercises 3.2 and 3.3 for r = 2, 4, and 16.

ru: Выполните упражнения 3.2 и 3.3 для r = 2, 4, 16.

## solution

[ex.3.4.cpp](./ex.3.4.cpp)

```
$ ./ex.3.4
old int : N=1000	R=2	avg=0.497	stddev=0.499991
old real: N=1000	R=2	avg=0.534	stddev=0.498843
new int : N=1000	R=2	avg=0.503	stddev=0.499991
new real: N=1000	R=2	avg=0.514	stddev=0.499804
old int : N=10000	R=2	avg=0.4969	stddev=0.49999
old real: N=10000	R=2	avg=0.4992	stddev=0.499999
new int : N=10000	R=2	avg=0.4959	stddev=0.499983
new real: N=10000	R=2	avg=0.5017	stddev=0.499997
old int : N=100000	R=2	avg=0.49919	stddev=0.499999
old real: N=100000	R=2	avg=0.49781	stddev=0.499995
new int : N=100000	R=2	avg=0.49963	stddev=0.5
new real: N=100000	R=2	avg=0.5	stddev=0.5
old int : N=1000000	R=2	avg=0.501002	stddev=0.499999
old real: N=1000000	R=2	avg=0.49961	stddev=0.5
new int : N=1000000	R=2	avg=0.499698	stddev=0.5
new real: N=1000000	R=2	avg=0.499524	stddev=0.5
old int : N=1000	R=4	avg=1.477	stddev=1.14345
old real: N=1000	R=4	avg=1.558	stddev=1.13077
new int : N=1000	R=4	avg=1.498	stddev=1.10995
new real: N=1000	R=4	avg=1.475	stddev=1.12933
old int : N=10000	R=4	avg=1.4987	stddev=1.11785
old real: N=10000	R=4	avg=1.5013	stddev=1.11937
new int : N=10000	R=4	avg=1.4837	stddev=1.11505
new real: N=10000	R=4	avg=1.4988	stddev=1.12071
old int : N=100000	R=4	avg=1.49797	stddev=1.11633
old real: N=100000	R=4	avg=1.49799	stddev=1.11828
new int : N=100000	R=4	avg=1.4991	stddev=1.12101
new real: N=100000	R=4	avg=1.50672	stddev=1.11704
old int : N=1000000	R=4	avg=1.50254	stddev=1.11812
old real: N=1000000	R=4	avg=1.49961	stddev=1.11766
new int : N=1000000	R=4	avg=1.4973	stddev=1.11779
new real: N=1000000	R=4	avg=1.50122	stddev=1.11832
old int : N=1000	R=10	avg=4.447	stddev=2.85818
old real: N=1000	R=10	avg=4.669	stddev=2.89921
new int : N=1000	R=10	avg=4.561	stddev=2.86501
new real: N=1000	R=10	avg=4.537	stddev=2.87309
old int : N=10000	R=10	avg=4.4827	stddev=2.86096
old real: N=10000	R=10	avg=4.5134	stddev=2.87256
new int : N=10000	R=10	avg=4.4857	stddev=2.8697
new real: N=10000	R=10	avg=4.5252	stddev=2.86945
old int : N=100000	R=10	avg=4.50087	stddev=2.8674
old real: N=100000	R=10	avg=4.49802	stddev=2.87352
new int : N=100000	R=10	avg=4.49566	stddev=2.87039
new real: N=100000	R=10	avg=4.50165	stddev=2.87414
old int : N=1000000	R=10	avg=4.49987	stddev=2.8718
old real: N=1000000	R=10	avg=4.49907	stddev=2.8712
new int : N=1000000	R=10	avg=4.50274	stddev=2.8711
new real: N=1000000	R=10	avg=4.49543	stddev=2.87307
old int : N=1000	R=16	avg=7.584	stddev=4.59183
old real: N=1000	R=16	avg=7.545	stddev=4.68188
new int : N=1000	R=16	avg=7.342	stddev=4.71222
new real: N=1000	R=16	avg=7.332	stddev=4.54728
old int : N=10000	R=16	avg=7.4903	stddev=4.60803
old real: N=10000	R=16	avg=7.5324	stddev=4.61334
new int : N=10000	R=16	avg=7.5579	stddev=4.61706
new real: N=10000	R=16	avg=7.5488	stddev=4.61173
old int : N=100000	R=16	avg=7.52035	stddev=4.61455
old real: N=100000	R=16	avg=7.47781	stddev=4.60865
new int : N=100000	R=16	avg=7.4994	stddev=4.60816
new real: N=100000	R=16	avg=7.49687	stddev=4.59989
old int : N=1000000	R=16	avg=7.50596	stddev=4.60835
old real: N=1000000	R=16	avg=7.50148	stddev=4.60982
new int : N=1000000	R=16	avg=7.50009	stddev=4.60818
new real: N=1000000	R=16	avg=7.50108	stddev=4.60767
old int : N=1000	R=100	avg=50.1	stddev=28.9004
old real: N=1000	R=100	avg=49.708	stddev=29.2329
new int : N=1000	R=100	avg=49.03	stddev=29.1487
new real: N=1000	R=100	avg=48.186	stddev=29.0792
old int : N=10000	R=100	avg=49.1279	stddev=28.9083
old real: N=10000	R=100	avg=49.7148	stddev=28.8586
new int : N=10000	R=100	avg=49.1011	stddev=28.9412
new real: N=10000	R=100	avg=49.5217	stddev=28.9981
old int : N=100000	R=100	avg=49.3593	stddev=28.8209
old real: N=100000	R=100	avg=49.3742	stddev=28.8524
new int : N=100000	R=100	avg=49.4913	stddev=28.9192
new real: N=100000	R=100	avg=49.6234	stddev=28.8546
old int : N=1000000	R=100	avg=49.4779	stddev=28.8458
old real: N=1000000	R=100	avg=49.511	stddev=28.8666
new int : N=1000000	R=100	avg=49.5236	stddev=28.8634
new real: N=1000000	R=100	avg=49.4844	stddev=28.8453
old int : N=1000	R=1000	avg=498.4	stddev=288.68
old real: N=1000	R=1000	avg=501.566	stddev=292.385
new int : N=1000	R=1000	avg=502.702	stddev=291.464
new real: N=1000	R=1000	avg=493.338	stddev=285.499
old int : N=10000	R=1000	avg=498.948	stddev=288.652
old real: N=10000	R=1000	avg=501.636	stddev=288.636
new int : N=10000	R=1000	avg=498.797	stddev=287.983
new real: N=10000	R=1000	avg=501.823	stddev=287.548
old int : N=100000	R=1000	avg=500.728	stddev=288.764
old real: N=100000	R=1000	avg=498.228	stddev=288.545
new int : N=100000	R=1000	avg=498.617	stddev=289.107
new real: N=100000	R=1000	avg=500.131	stddev=288.804
old int : N=1000000	R=1000	avg=499.529	stddev=288.753
old real: N=1000000	R=1000	avg=499.412	stddev=288.347
new int : N=1000000	R=1000	avg=499.2	stddev=288.897
new real: N=1000000	R=1000	avg=499.096	stddev=288.619
```
