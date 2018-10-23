open BsReactNative;
open Navigation;

module Styles = {
  open Style;

  let listItem = style([padding(Pt(10.))]);

  let listItemText = style([fontSize(Float(16.))]);
};

type screen = {
  name: string,
  route: Config.route,
};

type examples = array(screen);

let examples = [|
  {name: "Appbar Example", route: Config.AppbarExample},
  {name: "Banner Example", route: Config.BannerExample},
  {name: "Bottom Navigation Example", route: Config.BottomNavigationExample},
  {name: "Button Example", route: Config.ButtonExample},
  {name: "Card Example", route: Config.CardExample},
  {name: "Chip Example", route: Config.ChipExample},
  {name: "Checkbox Example", route: Config.CheckboxExample},
  {name: "Dialog Example", route: Config.DialogExample},
  {name: "Divider Example", route: Config.DividerExample},
  {name: "FAB Example", route: Config.FABExample},
  {name: "IconButton Example", route: Config.IconButtonExample},
  {name: "ListAccordion Example", route: Config.ListAccordionExample},
  {name: "ListSection Example", route: Config.ListSectionExample},
  {name: "ProgressBar Example", route: Config.ProgressBarExample},
  {name: "RadioButton Example", route: Config.RadioButtonExample},
  {name: "Searchbar Example", route: Config.SearchbarExample},
  {name: "Snackbar Example", route: Config.SnackbarExample},
  {name: "Surface Example", route: Config.SurfaceExample},
  {name: "Switch Example", route: Config.SwitchExample},
  {name: "TextInput Example", route: Config.TextInputExample},
  {name: "TouchableRipple Example", route: Config.TouchableRippleExample},
  {name: "Typography Example", route: Config.TypographyExample},
|];

let keyExtractor = (_item, index) => string_of_int(index);

let renderItem = (navigation: StackNavigator.navigation) =>
  FlatList.renderItem((screen: FlatList.renderBag(screen)) =>
    <Paper.List.Item
      title={screen.item.name}
      style=Styles.listItem
      onPress={
        _event =>
          Js.Global.setTimeout(() => navigation.push(screen.item.route), 0)
          |> ignore
      }
    />
  );

let component = ReasonReact.statelessComponent("Home");

let make = (~navigation: StackNavigator.navigation, _children) => {
  ...component,
  render: _self =>
    <StackNavigator.Screen headerTitle="Example App" navigation>
      ...{
           () =>
             <View>
               <FlatList
                 data=examples
                 keyExtractor
                 renderItem={renderItem(navigation)}
                 itemSeparatorComponent={
                   FlatList.separatorComponent(
                     (_props: FlatList.separatorProps(screen)) =>
                     <Paper.Divider />
                   )
                 }
               />
             </View>
         }
    </StackNavigator.Screen>,
};
