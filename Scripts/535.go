
import (
	"fmt"
	"strconv"
)

type Codec struct {
	count int
	m     map[int]string
}

func Constructor() Codec {
	c := Codec{0, map[int]string{}}
	return c
}

// Encodes a URL to a shortened URL.
func (this *Codec) encode(longUrl string) string {
	this.count++
	this.m[this.count] = longUrl
	res := strconv.Itoa(this.count)
	return res
}

// Decodes a shortened URL to its original URL.
func (this *Codec) decode(shortUrl string) string {
	index, _ := strconv.Atoi(shortUrl)
	return this.m[index]
}

/**
 * Your Codec object will be instantiated and called as such:
 * obj := Constructor();
 * url := obj.encode(longUrl);
 * ans := obj.decode(url);
 */
