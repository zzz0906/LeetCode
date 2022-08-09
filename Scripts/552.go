func checkRecord(n int) int {
	mod := 1e9 + 7
	var all int64 = 0
	var al int64 = 1
	var ap int64 = 1
	var aa int64 = 2
	var nall int64 = 1
	var nal int64 = 1
	var nap int64 = 2

	for (let i = 1; i <= n; i++) {
		var ALL int64 = 0
		var AL int64 = 0
		var AP int64 = 0
		var AA int64 = 0
		var NALL int64 = 0
		var NAL int64 = 0
		var NAP int64 = 0
		AP += all + aa + al + ap
		AL += aa + ap
		ALL += al

		NAP += nall + nal + nap
		AA += nall + nal + nap
		NALL += nal + 
	}
	return int(all)
}