cat ./上证指数2021-日期-时间-开-高-低-收-成交量-成交额.csv|grep 15:00|awk '{print $1,$2,$6}'|less
