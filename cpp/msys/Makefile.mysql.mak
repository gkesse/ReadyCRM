GCONNECT =\
	mysql -h $(GMYSQL_HOST) -u $(GMYSQL_USER) -P $(GMYSQL_PORT) -p$(GMYSQL_PASS)
    
drop_db: drop_db_run show_db

connect:
	$(GCONNECT)
show_db:
	$(GCONNECT) -e "show databases"
drop_db_run:
	$(GCONNECT) -e "drop database $(GMYSQL_DATABASE)"
