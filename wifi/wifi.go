// this is a simple program to automate logging in.
package main

import (
	"flag"
	"fmt"
	"log"
	"net/http"
	"strings"
)

var (
	username string
	password string
)

func init() {
	flag.StringVar(&username, "u", "", "username to log in with")
	flag.StringVar(&password, "p", "", "password to log in with")
	flag.Parse()
}

func main() {
	body := strings.NewReader(fmt.Sprintf(`auth_user=%v&auth_pass=%v&accept=Continue`, username, password))
	req, err := http.NewRequest("POST", "https://studentwireless.clark.edu:8003/index.php?zone=stuwrls", body)
	if err != nil {
		log.Panic(err)
	}
	req.Header.Set("Content-Type", "application/x-www-form-urlencoded")

	resp, err := http.DefaultClient.Do(req)
	if err != nil {
		log.Panic(err)
	}
	defer resp.Body.Close()
}
