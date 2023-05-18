
import islpy as isl

setA = ''
mapA = ''

def callbackPoints(p,ls):
    return ls.append(p)

def extract_iteration_space(domain):

    pointList = []
    domain.foreach_point(pointList.append)

    #Convert Point object to strings
    pointList = [point.to_str() for point in pointList]
    return pointList

def extract_schedule_pattern(domain,schedule):

    schedPattern = []
    doSch = domain.apply(schedule)
    doSch.foreach_point(schedPattern.append)

    #Convert Point object to strings
    schedPattern = [patt.to_str() for patt in schedPattern]

    return schedPattern

if __name__ == '__main__':

    domain = isl.Set(input("Enter domain string: "))
    schedule = isl.Map(input("Enter Schedule string: "))

    print("Iteration Space: ")
    print(extract_iteration_space(domain))
    print('\n')
    print("Schedule Pattern Sequence: ")
    print(extract_schedule_pattern(domain,schedule))


