## Setup MySQL

---

### Get the docker image

```JSON
$ docker pull mysql:8.0.23
$ docker images
```

![](https://z3.ax1x.com/2021/08/17/fh99nx.png)

### Start MySQL Image and Load Config, persisted data to the host host

```
$ vim mysql8.0.23.sh
```

```
#!/bin/sh
docker run \
-p 3306:3306 \
--name mysql \
--privileged=true \
--restart unless-stopped \
-v /Users/saberda/Documents/Code/PPManage/mysql8.0.23/mysql:/etc/mysql \
-v /Users/saberda/Documents/Code/PPManage/mysql8.0.23/logs:/logs \
-v /Users/saberda/Documents/Code/PPManage/mysql8.0.23/data:/var/lib/mysql \
-v /Users/saberda/Documents/Code/PPManage/mysql8.0.23/sql:/home \
-v /etc/localtime:/etc/localtime \
-e MYSQL_ROOT_PASSWORD=********* \
-d mysql:8.0.23
```

```
$ sh mysql8.0.20.sh
$ docker ps -a
```

![](https://z3.ax1x.com/2021/08/17/fh9kND.png)

If we want to change the MySQL image config, we should change the ```mysql8.0.23.sh``` file. And remember to restart our docker after changing.

#### Copy the sql file into image

```
$ docker cp /Users/saberda/Documents/Code/PPManage/PatientPortalServer-main/sql mysql:/home/
```

#### Launch MySQL docker image

```
$ docker exec -it mysql bash 

# mysql -h localhost -u root -p
Enter password:

# \. initialize_db.sql
```

<img src="https://z3.ax1x.com/2021/08/17/fhCnG4.png" style="zoom:33%;" />

---

### Use DBrever to visualize database

---

#### Step 1: Set up environment settings

<img src="https://z3.ax1x.com/2021/08/17/fhCFrq.png" style="zoom:30%;" />

#### Step 2: Connect with database

<img src="https://z3.ax1x.com/2021/08/17/fhCEZV.png" style="zoom:30%;" />

---

