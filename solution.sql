CREATE TABLE query1 AS

SELECT GENRES.NAME AS name,COUNT(HASAGENRE.movieid) AS moviecount FROM

HASAGENRE INNER JOIN GENRES ON

GENRES.GENREID=HASAGENRE.genreid

GROUP BY GENRES.NAME;

CREATE TABLE query2 AS 
select GENRES.name as name , avg(ratings.rating) as rating 
from  hasagenre INNER JOIN ratings  ON hasagenre.movieid = ratings.movieid
INNER JOIN genres ON genres.genreid = hasagenre.genreid   group by GENRES.NAME
;
CREATE TABLE query3  AS
select  movies.title as title, count(ratings.movieid) as countofratings 
from movies INNER JOIN ratings
ON movies.movieid = ratings.movieid 
group by movies.title
having count(ratings.movieid)>=10 
;
CREATE TABLE query5 AS 
select title as title , avg(rating) as average 
from movies , ratings 
where movies.movieid = ratings.movieid group by movies.movieid
;
CREATE TABLE query6 AS 

select avg(r.rating) as average from ratings r, genres g, hasagenre h

 where r.movieid = h.movieid and g.genreid = h.genreid and g.name = 'Comedy';
 
CREATE TABLE query7 AS 

select avg(r.rating) as average  from ratings r, genres g, hasagenre h

 where r.movieid = h.movieid and g.genreid = h.genreid and g.name = 'Comedy' 
 
 and  
(select avg(r.rating) as average  from ratings r, genres g, hasagenre h

 where r.movieid = h.movieid and g.genreid = h.genreid and g.name = 'Romance' );

CREATE TABLE query8 AS 

select avg(r.rating) as average  from ratings r, genres g, hasagenre h

 where r.movieid = h.movieid and g.genreid = h.genreid and g.name = 'Comedy'

 and not   
 
 (select avg(r.rating) as average  from ratings r, genres g, hasagenre h

 where r.movieid = h.movieid and g.genreid = h.genreid and g.name ='Romance');