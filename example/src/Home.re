open BsReactNative;
open Navigation;

module Styles = {
  open Style;

  let listItem =
    style([paddingVertical(Pt(15.)), paddingHorizontal(Pt(10.))]);

  let listItemText = style([fontSize(Float(16.))]);
};

type screen = {
  id: int,
  name: string,
  route: Config.route,
};

type examples = array(screen);

let examples = [|
  {id: 1, name: "Snackbar Example", route: Config.SnackbarExample},
|];

let keyExtractor = (item, _index) => string_of_int(item.id);

let renderItem = (navigation: StackNavigator.navigation) =>
  FlatList.renderItem((screen: FlatList.renderBag(screen)) =>
    <Paper.TouchableRipple
      style=Styles.listItem
      onPress={
        _event =>
          Js.Global.setTimeout(() => navigation.push(screen.item.route), 0)
          |> ignore
      }>
      <Text style=Styles.listItemText>
        {ReasonReact.string(screen.item.name)}
      </Text>
    </Paper.TouchableRipple>
  );

let component = ReasonReact.statelessComponent("Home");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  render: _self =>
    <StackNavigator.Screen headerTitle="Home" navigation>
      ...{
           () =>
             <View>
               <FlatList
                 data=examples
                 keyExtractor
                 renderItem={renderItem(navigation)}
               />
             </View>
         }
    </StackNavigator.Screen>,
};
