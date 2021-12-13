# docker tip

## 자주쓰는 도커 명령어

1. docker images
* 도커 image list 보여주는 명령어
2. docker run 
* 도커 컨태이너 생성하는 명령어이다. 
* 기본적으로 -itd 옵션을 사용하는데 터미널로 실행하는데 백그라운드로 띄울때 사용된다.
<pre>
-i, --interactive                    Keep STDIN open even if not attached
-t, --tty                            Allocate a pseudo-TTY
-d, --detach                         Run container in background and print container ID
</pre>
* 또 사용하는 옵션으로는 port name 등이 있다. (ex -p 15000:22, --name test)
3. docker exec 
* docker run과 다르게 구동하고 있는 컨테이너에 명령을 내리는 옵션이다.
* run과 비슷하게 -it, -itd 옵션등을 이용한다.
4. docker ps
* docker 컨테이너 리스트를 보여주는 명령어
5. docker commit
* ```docker commit CONTATINER IMAGE_NAME``` 으로 사용
* container 이름을 이미지로 저장할때 사용
6. 도커 이미지 저장 및 로드
* docker hub를 사용해서 push pull 방식으로 사용하는방법 말고 파일로 export import 하는방식
* docker save
    * docker image를 tar파일로 정장하기 위한 커맨드
    * ```docker save [옵션] <파일명> [이미지명]```
    * ex) docker save -o nginx.tar nginx:latest
* docker load
    * tar파일을 image로 만드는 커맨드
    * ```docker load -i <tar파일명>```
