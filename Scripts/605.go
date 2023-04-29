func canPlaceFlowers(flowerbed []int, n int) bool {
	if n == 0 {
		return true
	}
	length := len(flowerbed)
	flowerbed = append([]int{0}, flowerbed...)
	flowerbed = append(flowerbed, 0)
	for i := 1; i <= length; i++ {
		if (flowerbed[i-1] == 0) && (flowerbed[i] == 0) && (flowerbed[i+1] == 0) {
			n--
			flowerbed[i] = 1
		}
		if n == 0 {
			return true
		}
	}
	return false
}