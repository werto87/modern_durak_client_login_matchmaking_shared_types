#ifndef C02CDB99_AA83_45B0_83E7_8C8BC254A8F2
#define C02CDB99_AA83_45B0_83E7_8C8BC254A8F2

#include <boost/algorithm/string.hpp>
#include <boost/fusion/adapted/struct/adapt_struct.hpp>
#include <boost/fusion/adapted/struct/define_struct.hpp>
#include <boost/fusion/algorithm/query/count.hpp>
#include <boost/fusion/functional.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/fusion/include/algorithm.hpp>
#include <boost/fusion/include/at.hpp>
#include <boost/fusion/include/count.hpp>
#include <boost/fusion/include/define_struct.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/fusion/sequence/intrinsic_fwd.hpp>
#include <boost/hana/assert.hpp>
#include <boost/hana/at_key.hpp>
#include <boost/hana/equal.hpp>
#include <boost/hana/find.hpp>
#include <boost/hana/for_each.hpp>
#include <boost/hana/integral_constant.hpp>
#include <boost/hana/map.hpp>
#include <boost/hana/optional.hpp>
#include <boost/hana/pair.hpp>
#include <boost/hana/tuple.hpp>
#include <boost/hana/type.hpp>
#include <boost/json.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/range_c.hpp>
#include <cstddef>
#include <durak/gameData.hxx>
#include <durak/gameOption.hxx>
#include <iostream>
#include <map>
#include <optional>
#include <sstream>
#include <string>
#include <utility>
#include <variant>
#include <vector>

typedef std::vector<std::pair<std::string, long long int> > UserTimeMilliseconds;

namespace shared_class
{
enum struct TimerType
{
  noTimer,
  resetTimeOnNewRound,
  addTimeOnNewRound
};
}

BOOST_FUSION_DEFINE_STRUCT ((shared_class), DurakTimers, (shared_class::TimerType, timerType) (UserTimeMilliseconds, runningTimeUserTimePointMilliseconds) (UserTimeMilliseconds, pausedTimeUserDurationMilliseconds))
BOOST_FUSION_DEFINE_STRUCT ((shared_class), TimerOption, (shared_class::TimerType, timerType) (uint64_t, timeAtStartInSeconds) (uint64_t, timeForEachRoundInSeconds))
namespace shared_class
{
enum struct OpponentCards
{
  showNumberOfOpponentCards,
  showOpponentCards,
};
}
BOOST_FUSION_DEFINE_STRUCT ((shared_class), GameOption, (durak::GameOption, gameOption) (shared_class::TimerOption, timerOption) (uint64_t, computerControlledPlayerCount) (shared_class::OpponentCards, opponentCards)) // TODO-TEMPLATE add game options

std::optional<std::string> inline errorInGameOption (shared_class::GameOption const &)
{
  // TODO-TEMPLATE check Game option
  return std::nullopt;
}

BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), JoinChannel, (std::string, channel))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), JoinChannelSuccess, (std::string, channel))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), JoinChannelError, (std::string, channel) (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), CreateAccount, (std::string, accountName) (std::string, password))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), CreateAccountCancel, )
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), CreateAccountSuccess, (std::string, accountName))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), CreateAccountError, (std::string, accountName) (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), LoginAccount, (std::string, accountName) (std::string, password))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), LoginAccountCancel, )
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), LoginAccountSuccess, (std::string, accountName))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), LoginAccountError, (std::string, accountName) (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), LogoutAccount, )
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), LogoutAccountSuccess, )
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), LogoutAccountError, )
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), BroadCastMessage, (std::string, channel) (std::string, message))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), BroadCastMessageSuccess, (std::string, channel) (std::string, message))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), BroadCastMessageError, (std::string, channel) (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), LeaveChannel, (std::string, channel))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), LeaveChannelSuccess, (std::string, channel))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), LeaveChannelError, (std::string, channel) (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), Message, (std::string, fromAccount) (std::string, channel) (std::string, message))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), CreateGameLobby, (std::string, name) (std::string, password))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), CreateGameLobbySuccess, (std::string, name))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), CreateGameLobbyError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), JoinGameLobby, (std::string, name) (std::string, password))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), JoinGameLobbySuccess, )
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), JoinGameLobbyError, (std::string, name) (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), GameOptionError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), UserInGameLobby, (std::string, accountName))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), UsersInGameLobby, (std::string, name) (std::vector<user_matchmaking::UserInGameLobby>, users) (size_t, maxUserSize) (shared_class::GameOption, durakGameOption))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), SetMaxUserSizeInCreateGameLobby, (size_t, maxUserSize))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), SetMaxUserSizeInCreateGameLobbyError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), MaxUserSizeInCreateGameLobby, (size_t, maxUserSize))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), LeaveGameLobby, )
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), LeaveGameLobbySuccess, )
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), LeaveGameLobbyError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), WantToRelog, (std::string, accountName) (std::string, destination))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), RelogTo, (bool, wantsToRelog))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), RelogToCreateGameLobbySuccess, )
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), RelogToGameSuccess, )
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), RelogToError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), CreateGame, )
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), CreateGameError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), StartGame, )
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), StartGameError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), JoinMatchMakingQueue, (bool, isRanked))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), JoinMatchMakingQueueSuccess, )
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), JoinMatchMakingQueueError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), AskIfUserWantsToJoinGame, )
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), AskIfUserWantsToJoinGameTimeOut, )
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), GameStartCanceled, )
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), GameStartCanceledRemovedFromQueue, )
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), WantsToJoinGame, (bool, answer))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), WantsToJoinGameError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), LeaveQuickGameQueue, )
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), LeaveQuickGameQueueSuccess, )
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), LeaveQuickGameQueueError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), LoginAsGuest, )
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), LoginAsGuestSuccess, (std::string, accountName))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), RatingChanged, (size_t, oldRating) (size_t, newRating))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), UnhandledMessageError, (std::string, msg) (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), ProxyStarted, )
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), ProxyStopped, )
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), ConnectGameError, (std::string, error))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), UnhandledEventError, (std::string, unhandledEvent) (std::string, reason))
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), GetMatchmakingLogic, )
BOOST_FUSION_DEFINE_STRUCT ((user_matchmaking), MatchmakingLogic, (std::string, logic))

// clang-format off
namespace user_matchmaking{
static boost::hana::tuple<
JoinChannel,
JoinChannelSuccess,
JoinChannelError,
CreateAccount,
CreateAccountCancel,
CreateAccountSuccess,
CreateAccountError,
LoginAccount,
LoginAccountCancel,
LoginAccountSuccess,
LoginAccountError,
LogoutAccount,
LogoutAccountSuccess,
LogoutAccountError,
BroadCastMessage,
BroadCastMessageSuccess,
BroadCastMessageError,
LeaveChannel,
LeaveChannelSuccess,
LeaveChannelError,
Message,
CreateGameLobby,
CreateGameLobbySuccess,
CreateGameLobbyError,
JoinGameLobby,
JoinGameLobbySuccess,
JoinGameLobbyError,
GameOptionError,
UserInGameLobby,
UsersInGameLobby,
SetMaxUserSizeInCreateGameLobby,
SetMaxUserSizeInCreateGameLobbyError,
MaxUserSizeInCreateGameLobby,
LeaveGameLobby,
LeaveGameLobbySuccess,
LeaveGameLobbyError,
WantToRelog,
RelogTo,
RelogToCreateGameLobbySuccess,
RelogToGameSuccess,
RelogToError,
CreateGame,
CreateGameError,
StartGame,
StartGameError,
JoinMatchMakingQueue,
JoinMatchMakingQueueSuccess,
JoinMatchMakingQueueError,
AskIfUserWantsToJoinGame,
AskIfUserWantsToJoinGameTimeOut,
GameStartCanceled,
GameStartCanceledRemovedFromQueue,
WantsToJoinGame,
WantsToJoinGameError,
LeaveQuickGameQueue,
LeaveQuickGameQueueSuccess,
LeaveQuickGameQueueError,
LoginAsGuest,
LoginAsGuestSuccess,
RatingChanged,
UnhandledMessageError,
shared_class::GameOption,
ConnectGameError,
ProxyStarted,
ProxyStopped,
GetMatchmakingLogic,
MatchmakingLogic
  >  const  userMatchmaking{};
}
// clang-format on

#endif /* C02CDB99_AA83_45B0_83E7_8C8BC254A8F2 */
