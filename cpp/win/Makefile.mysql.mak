GCONNECT =\
	mysql -h $(GMYSQL_HOST) -u $(GMYSQL_USER) -P $(GMYSQL_PORT) -p$(GMYSQL_PASS)
    
db_drop: db_drop_run db_show

# connect
connect:
	$(GCONNECT)
# grant
grant_show:
	$(GCONNECT) -e "show grants"
# user
user_show:
	$(GCONNECT) -e "select user, host, account_locked, password_expired from mysql.user"
user_drop:
	$(GCONNECT) -e "drop user '$(GMYSQL_USER_REF)'@'$(GMYSQL_HOST_REF)'"
user_db:
	$(GCONNECT) -e "grant all privileges on $(GMYSQL_DATABASE).* to '$(GMYSQL_USER_REF)'@'$(GMYSQL_HOST_REF)' identified by '$(GMYSQL_PASS_REF)'"
# db
db_show:
	$(GCONNECT) -e "show databases"
db_drop_run:
	$(GCONNECT) -e "drop database $(GMYSQL_DATABASE)"
# table
table_show:
	$(GCONNECT) -e "use $(GMYSQL_DATABASE) ; show tables"
table_show_f:
	$(GCONNECT) -e "use $(GMYSQL_DATABASE) ; show tables like '%$(GMYSQL_TABLE_FILTER)%'"
table_show_s:
	$(GCONNECT) -e "use $(GMYSQL_DATABASE) ; describe $(GMYSQL_TABLE)"
table_show_a:
	$(GCONNECT) -e "use $(GMYSQL_DATABASE) ; select count(*) iCOUNT from $(GMYSQL_TABLE)"
