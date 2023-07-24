#===================================================================================
# Replace the value for CTEST_PROJECT_NAME with your project name and URL
#===================================================================================

# set(CTEST_PROJECT_NAME  "CDashboardExample")
# set(CTEST_SUBMIT_URL    "http://localhost/submit.php?project=${CTEST_PROJECT_NAME}")
# set(CTEST_USE_LAUNCHERS NO)

#admin@example.org
#vscode ➜ /workspace/build $ ctest -D Experimental



## This file should be placed in the root directory of your project.
## Then modify the CMakeLists.txt file in the root directory of your
## project to incorporate the testing dashboard.
##
## # The following are required to submit to the CDash dashboard:
##   ENABLE_TESTING()
##   INCLUDE(CTest)

set(CTEST_PROJECT_NAME "MyTestProjectName")
set(CTEST_NIGHTLY_START_TIME "01:00:00 UTC")

set(CTEST_DROP_METHOD "https")
set(CTEST_DROP_SITE "my.cdash.org")
set(CTEST_DROP_LOCATION "/submit.php?project=MyTestProjectLocation")
set(CTEST_DROP_SITE_CDASH TRUE)

# # CTEST_CDASH_AUTH_TOKEN should be set as an environment variable containing your CDash authorization token
# # Skip upload if it is not set (could happen for PR build in a fork for instance)
# if (DEFINED ENV{CTEST_CDASH_AUTH_TOKEN})
# 	ctest_submit(HTTPHEADER "Authorization: Bearer $ENV{CTEST_CDASH_AUTH_TOKEN}")
# else()
# 	message(STATUS "CTEST_CDASH_AUTH_TOKEN not set, skipping upload to CDash")
# endif()