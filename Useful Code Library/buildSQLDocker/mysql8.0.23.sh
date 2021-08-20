
#!/bin/sh
docker run \
-p 3307:3307 \
--name neurelis \
--privileged=true \
--restart unless-stopped \
-v /Users/saberda/Documents/Code/PPManage/mysql8.0.23/mysql:/etc/mysql \
-v /Users/saberda/Documents/Code/PPManage/mysql8.0.23/logs:/logs \
-v /Users/saberda/Documents/Code/PPManage/mysql8.0.23/data:/var/lib/mysql \
-v /Users/saberda/Documents/Code/PPManage/PatientPortalServer-main/sql:/home \
-v /etc/localtime:/etc/localtime \
-e MYSQL_ROOT_PASSWORD=L456456lgd \
-d mysql:8.0.23
