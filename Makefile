all:
	g++ --std=c++11 -o main ./main.cpp ./notification.cpp ./log_module.cpp ./loger.cpp ./unix_crawler.cpp -I ./
clean:
	rm -rf ./main
